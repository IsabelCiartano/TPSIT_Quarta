#include "shared.h"

/*--------------------------------------------------------------------
  Shared Memory
	v 2.1 	(Novembre 2016)
----------------------------------------------------------------------
	Libreria di interfaccia per la gestione di aree di
	memoria condivisa

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

/* shared_create()
   RICEVE: chiave ipc, dimensioni dell'area da creare, puntatore a id
   RESTITUISCE: un puntatore alla shared memory, NULL in caso di errore
                id della shared (ricevuto per referenza, lo restituisce compilato) */
void* shared_create(key_t ipc_key, int len, int* shm_id) {
	void* ret;

	/* shmget()        crea un segmento di memoria condivisa
	   ipc_key      --> chiave univoca associata al segmento
	   len          --> dimensione del segmento in byte
	   3o parametro --> operazioni da compiere messe in OR:
	                    IPC_CREAT: crea il segmento
	                    IPC_EXCL: restituisce errore se esiste gia'
	                    0666: permessi di accesso (rw-rw-rw-) */
	*shm_id = shmget(ipc_key, len, IPC_CREAT | IPC_EXCL | 0666);
	if (*shm_id < 0)
		return NULL;

	/* shmat()         collega il segmento allo spazio di indirizzamento del processo
	   *shm_id      --> identificatore del segmento
	   NULL         --> il sistema sceglie l'indirizzo
	   0            --> permessi di lettura/scrittura */
	ret = shmat(*shm_id, NULL, 0);
	return ret;
}

/* shared_find()
   RICEVE: la chiave IPC, puntatore a id
   RESTITUISCE: indirizzo della shared memory, NULL in caso di errore
                id della shared (ricevuto per referenza, lo restituisce compilato) */
void* shared_find(key_t ipc_key, int* shm_id) {
	void* ret;

	/* shmget()        recupera un segmento di memoria condivisa esistente
	   ipc_key      --> chiave univoca associata al segmento
	   0            --> dimensione non utilizzata
	   IPC_EXCL     --> flag per indicare che il segmento deve esistere */
	*shm_id = shmget(ipc_key, 0, IPC_EXCL);
	if (*shm_id < 0)
		return NULL;

	/* shmat()         collega il segmento allo spazio di indirizzamento del processo */
	ret = shmat(*shm_id, NULL, 0);
	return ret;
}

/* shared_remove()
   RICEVE: id della shared memory
   RESTITUISCE: 0 in caso di successo, 1 in caso di errore */
int shared_remove(int shm_id) {
	int ret;

	/* shmctl()        esegue operazioni di controllo sul segmento
	   shm_id       --> identificatore del segmento
	   IPC_RMID     --> operazione di RIMOZIONE del segmento
	   NULL         --> non utilizzato per IPC_RMID */
	ret = shmctl(shm_id, IPC_RMID, NULL);

	return ((ret != -1) ? 0 : 1);
}
