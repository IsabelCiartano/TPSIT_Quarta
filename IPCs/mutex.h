/*
 * mutex.h
 * This file is part of DelpozzoSoft
 *
 * Copyright (C) 2020 - Delpozzo - Cuneo (CN)
 *
 * DelpozzoSoft is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * DelPozzosoft is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with DelpozzoSoft. If not, see <http://www.gnu.org/licenses/>.
 */

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

#ifndef __MUTEX_H
#define __MUTEX_H

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

/* Function prototypes */
int mutex_create(key_t ipc_key, int starting_value);
int mutex_find(key_t ipc_key);
int mutex_lock(int sem_id);
int mutex_unlock(int sem_id);
int mutex_remove(int sem_id);

#endif /* __MUTEX_H */
