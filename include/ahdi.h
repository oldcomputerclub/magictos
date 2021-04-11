/*
 * ahdi.h - AHDI-related structures and variables
 *
 * This file exists to allow AHDI stuff to be referenced by both
 * the BDOS and the BIOS.
 *
 * Copyright (C) 2014-2020 The EmuTOS development team
 *
 * Authors:
 *  RFB    Roger Burrows
 *
 * This file is distributed under the GPL, version 2 or at your
 * option any later version.  See doc/license.txt for details.
 */

#ifndef _AHDI_H
#define _AHDI_H

#define PUN_MAXUNITS    16      /* architectural */

typedef struct
{
    UWORD puns;                 /* number of physical devices */
    UBYTE pun[PUN_MAXUNITS];    /* bus/device for this partition (see below) */
    ULONG partition_start[PUN_MAXUNITS];
    ULONG cookie;               /* 'AHDI' if following valid */
    ULONG *cookie_ptr;          /* points to 'cookie' */
    UWORD version_num;          /* AHDI version */
    UWORD max_sect_siz;         /* maximum logical sector size */
    LONG reserved[PUN_MAXUNITS];
} PUN_INFO;

/* masks for pun[] array above: */
#define PUN_DEV         0x1f    /* device number of HD */
#define PUN_UNIT        0x7     /* Unit number */
#define PUN_SCSI        0x8     /* 1=SCSI 0=ACSI */
#define PUN_IDE         0x10    /* Falcon IDE */
#define PUN_REMOVABLE   0x40    /* Removable media */
#define PUN_VALID       0x80    /* zero if valid */

extern PUN_INFO *pun_ptr;

#endif /* _AHDI_H */
