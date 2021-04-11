/*
 * dma.h - dma definitions
 *
 * Copyright (C) 2001-2019 The EmuTOS development team
 *
 * Authors:
 *  LVL   Laurent Vogel
 *
 * This file is distributed under the GPL, version 2 or at your
 * option any later version.  See doc/license.txt for details.
 */

#ifndef DMA_H
#define DMA_H

#define DMA     ((volatile struct dma *) 0xFFFF8600)

struct dma {
    UWORD   pad0[2];
     WORD   data;       /* sector count, data register */
     WORD   control;    /* status/control register */
    UBYTE   pad1;
    UBYTE   addr_high;
    UBYTE   pad2;
    UBYTE   addr_med;
    UBYTE   pad3;
    UBYTE   addr_low;
    UBYTE   pad4;
                    /* the "mode/control" register is only present on the Falcon */
    UBYTE   modectl;    /* R: bit 3 is tested during write/format */
                        /* W: floppy density control (DD or HD) */
};

/*
 * Control register bits
 */
/*                      0x0001         not used */
#define DMA_NOT_NEWCDB  0x0002      /* not the start of a new CDB (ACSI only) */
#define DMA_A0          0x0002      /* signal A0 (floppy only) */
#define DMA_A1          0x0004      /* signal A1 (floppy only) */
#define DMA_CS_ACSI     0x0008      /* gates _CS: 1=>ACSI, 0=>floppy */
#define DMA_SCREG       0x0010      /* access sector count register */
/*                      0x0020         reserved */
/*                      0x0040         reserved */
#define DMA_DRQ_FLOPPY  0x0080      /* gates _DRQ: 1=>floppy, 0=>ACSI */
#define DMA_WRBIT       0x0100      /* write to floppy/ACSI via dma_data */

#define DMA_FLOPPY      DMA_DRQ_FLOPPY  /* DMA_DRQ_FLOPPY=1 && DMA_CS_ACSI=0 */

/*
 * Status register bits
 */
#define DMA_OK      0x0001          /* 1=ok, 0=error */
#define DMA_SCNOT0  0x0002          /* 1=sector count not 0 */
#define DMA_DATREQ  0x0004          /* 1=FDC data request signal */

/*
 * Falcon "mode/control" bits
 */
#define DMA_MCBIT3  0x08            /* must be zero before starting write */

void set_dma_addr(UBYTE *addr);

#endif /* DMA_H */
