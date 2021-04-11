/*
 * dma.c - DMA disk routines
 *
 * Copyright (C) 2011-2019 The EmuTOS development team
 *
 * This file is distributed under the GPL, version 2 or at your
 * option any later version.  See doc/license.txt for details.
 */

#include "emutos.h"
#include "dma.h"

void set_dma_addr(UBYTE *addr)
{
    UBYTE_ALIAS* b = (UBYTE_ALIAS*)&addr;

    DMA->addr_low = b[3];
    DMA->addr_med = b[2];
    DMA->addr_high = b[1];
}
