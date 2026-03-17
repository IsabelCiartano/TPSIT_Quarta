#include "mutex.h"

/*--------------------------------------------------------------------
  Mutex (Semaphore Wrapper)
	v 2.0 	(Novembre 2016)
----------------------------------------------------------------------
	Libreria wrapper per le funzioni di <sys/sem.h>
	(semplifica la gestione di un mutex)

	ITIS delpozzo - cuneo (CN)
	Settore Informatica
	Authors: Tosello

	Se modificate questo sorgente per favore fatene
	avere una copia agli autori originali, cosi' da
	permettere l'allineamento ed evitare la diffusione
	di cloni o fork che non garantiscano la compatibilita'
	verso il preesistente.

	Grazie.                     			L'autore
---------------------------------------------------------------------*/

/* Records per le chiamate a semop() per modificare il contenuto del mutex
   (semop() opera su un insieme IPC composto da semafori) */
static struct sembuf sem_lock = {
	0,          /* posizione del mutex nell'insieme IPC */
	-1,         /* toglie uno al valore del mutex */
	SEM_UNDO    /* il processo rilascia il mutex anche in caso di errore */
};

static struct sembuf sem_unlock = {
	0,          /* posizione del mutex nell'insieme IPC */
	+1,         /* aggiunge uno al valore del mutex */
	SEM_UNDO    /* il processo rilascia il mutex anche in caso di errore */
};

/* mutex_create()
   RICEVE: l'identificativo nel sistema dell'insieme IPC e il valore al quale
           inizializzare il mutex
   RESTITUISCE: un intero che identifica il mutex, -1 in caso di errore */
int mutex_create(key_t ipc_key, int starting_value) {
	int ret, sem_id;

	/* semget()       crea un insieme di semafori
	   ipc_key      --> chiave univoca associata al gruppo IPC
	   1            --> numero di semafori da creare
	   3o parametro --> operazioni da compiere messe in OR:
	                    IPC_CREAT: crea l'insieme IPC
	                    IPC_EXCL: restituisce un valore non valido nel caso
	                              in cui la struttura esista gia'
	                    0666: accesso consentito a tutti (in ottale - rw-rw-rw-) */
	sem_id = semget(ipc_key, 1, IPC_CREAT | IPC_EXCL | 0666);
	if (sem_id == -1)
		return sem_id;  /* errore: creazione fallita */

	/* semctl()         compie operazioni su un insieme di semafori
	   sem_id        --> id dell'insieme IPC
	   0             --> posizione del semaforo
	   SETVAL        --> operazione da eseguire: impostare il valore del semaforo
	   starting_value--> valore di inizializzazione */
	ret = semctl(sem_id, 0, SETVAL, starting_value);

	if (ret == -1)
		return ret;  /* errore: modifica fallita */

	return sem_id;
}

/* mutex_find()
   RICEVE: l'identificativo nel sistema dell'insieme IPC
   RESTITUISCE: un intero che identifica l'insieme di semafori, -1 in caso di errore */
int mutex_find(key_t ipc_key) {
	/* semget()         recupera un insieme di semafori
	   ipc_key       --> chiave univoca associata al gruppo di semafori
	   2o parametro  --> non utilizzato
	   3o parametro  --> indica che non si compiono operazioni sul gruppo di semafori */
	return semget(ipc_key, 0, 0);
}

/* mutex_lock()
   RICEVE: id dell'insieme di semafori
   RESTITUISCE: 0 in caso di successo, -1 in caso di errore */
int mutex_lock(int sem_id) {
	/* semop()
	   sem_id      --> identificativo dell'insieme di semafori
	   &sem_lock   --> operazione da effettuare
	   1           --> numero di operazioni contenute nel secondo argomento */
	return semop(sem_id, &sem_lock, 1);
}

/* mutex_unlock()
   RICEVE: id dell'insieme di semafori
   RESTITUISCE: 0 in caso di successo, -1 in caso di errore */
int mutex_unlock(int sem_id) {
	/* semop()
	   sem_id      --> identificativo dell'insieme di semafori
	   &sem_unlock --> operazione da effettuare
	   1           --> numero di operazioni contenute nel secondo argomento */
	return semop(sem_id, &sem_unlock, 1);
}

/* mutex_remove()
   RICEVE: id dell'insieme di semafori
   RESTITUISCE: 0 in caso di successo, -1 in caso di errore */
int mutex_remove(int sem_id) {
	/* semctl()
	   sem_id       --> id dell'insieme IPC
	   2o parametro --> ignorato
	   IPC_RMID     --> operazione di RIMOZIONE dell'insieme IPC */
	return semctl(sem_id, 0, IPC_RMID);
}
