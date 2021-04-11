/*
 * scc.h - header for SCC chip
 *
 * Copyright (C) 2013-2019 The EmuTOS development team
 *
 * Authors:
 *  RFB    Roger Burrows
 *
 * This file is distributed under the GPL, version 2 or at your
 * option any later version.  See doc/license.txt for details.
 */

#ifndef _SCC_H
#define _SCC_H

#if CONF_WITH_SCC
/*
 * structures
 */
typedef struct {
    UBYTE dum1;
    volatile UBYTE ctl;
    UBYTE dum2;
    volatile UBYTE data;
} PORT;
typedef struct {
    PORT portA;
    PORT portB;
} SCC;
#endif

#endif  /* _SCC_H */
