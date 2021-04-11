/*
 * chardev.h - bios devices
 *
 * Copyright (C) 2001-2019 The EmuTOS development team
 *
 * Authors:
 *  MAD   Martin Doering
 *  LVL   Laurent Vogel
 *
 * This file is distributed under the GPL, version 2 or at your
 * option any later version.  See doc/license.txt for details.
 */

#ifndef _CHARDEV_H
#define _CHARDEV_H

/* Prototypes */
LONG bconout2(WORD, WORD);
LONG bconout5(WORD, WORD);
LONG bcostat2(void);

LONG char_dummy(void);
LONG charout_dummy(WORD dev, WORD x);


/* internal init routine */

void chardev_init(void);

#endif /* _CHARDEV_H */
