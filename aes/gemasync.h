/*
 * gemasync.h - header for EmuTOS AES process synchronization functions
 *
 * Copyright (C) 2002-2020 The EmuTOS development team
 *
 * This file is distributed under the GPL, version 2 or at your
 * option any later version.  See doc/license.txt for details.
 */

#ifndef GEMASYNC_H
#define GEMASYNC_H

void azombie(EVB *e, UWORD ret);
void evinsert(EVB *e, EVB **root);
EVSPEC mwait(EVSPEC mask);
EVSPEC iasync(WORD afunc, LONG aparm);
UWORD apret(EVSPEC mask);
EVSPEC acancel(EVSPEC m);

#endif
