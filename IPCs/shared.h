/*
 * shared.h
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
 * along with VallauriSoft. If not, see <http://www.gnu.org/licenses/>.
 */

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

#ifndef __SHARED_H
#define __SHARED_H

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

/* Function prototypes */
void* shared_create(key_t ipc_key, int len, int* shm_id);
void* shared_find(key_t ipc_key, int* shm_id);
int   shared_remove(int shm_id);

#endif /* __SHARED_H */
