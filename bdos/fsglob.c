/*
 * fsglob.c - global variables for the file system
 *
 * Copyright (C) 2001 Lineo, Inc.
 *               2002-2019 The EmuTOS development team
 *
 * This file is distributed under the GPL, version 2 or at your
 * option any later version.  See doc/license.txt for details.
 */

/*
 *  Mod #          who date             modification
 *  -------------- --- ---------        ------------
 *  M01.01.1023.02 scc 10/23/86         Changed the definition of time and date
 *                                      to unsigned int
 *
 */
#include "emutos.h"
#include "fs.h"

/*
 * Global Filesystem related variables
 */

/*
 *  drvtbl -  root of the control block chains for every block device
 */
DMD *drvtbl[BLKDEVNUM];


/*
 *  sft -  system file table
 */
FTAB sft[OPNFILES];


/*
 * rwerr -  hard error number currently in progress
 */
long rwerr;
long errcode;


/*
 * errdrv -  drive on which error occurred
 */
int errdrv;
jmp_buf errbuf;
