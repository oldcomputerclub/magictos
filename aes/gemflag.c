/*      GEMFLAG.C       1/27/84 - 08/26/85      Lee Jay Lorenzen        */
/*      merge High C vers. w. 2.2 & 3.0         8/20/87         mdf     */

/*
*       Copyright 1999, Caldera Thin Clients, Inc.
*                 2002-2019 The EmuTOS development team
*
*       This software is licenced under the GNU Public License.
*       Please see LICENSE.TXT for further information.
*
*                  Historical Copyright
*       -------------------------------------------------------------
*       GEM Application Environment Services              Version 2.3
*       Serial No.  XXXX-0000-654321              All Rights Reserved
*       Copyright (C) 1987                      Digital Research Inc.
*       -------------------------------------------------------------
*/

#include "emutos.h"
#include "struct.h"
#include "aesvars.h"
#include "obdefs.h"

#include "gemasync.h"
#include "geminput.h"
#include "gemdosif.h"
#include "gemasm.h"
#include "gemflag.h"



void tchange(LONG c)            /* c=number of ticks that have gone by  */
{
    EVB *d;
    LONG c1;

    /*
     * pull pd's off the delay list that have waited long enough
     */
    d = dlr;
    while (d)
    {
        /* take a bite out of the amount of time the pd is waiting */
        c1 = c - d->e_parm;
        d->e_parm -= c;
        c = c1;

        /* finished waiting? */
        if (d->e_parm <= 0L)
        {
            d->e_parm = 0L;
            evremove(d, 0);
            d = dlr;
        }
        else
        {
            /*
             * set compare tick time to the amount the
             * first guy is waiting
             */
            disable_interrupts();
            CMP_TICK = d->e_parm;
            NUM_TICK = 0L;
            enable_interrupts();
            break;
        }
    }
}


WORD tak_flag(SPB *sy)
{
    /* count up */
    sy->sy_tas++;

    /*
     * if we didn't already own it and it wasn't free,
     * then wait for it; else claim ownership
     */
    if ((sy->sy_owner != rlr) && (sy->sy_tas != 1))
        sy->sy_tas--;
    else
        sy->sy_owner = rlr;

    return (sy->sy_owner == rlr);
}


void amutex(EVB *e, LONG ls)
{
    SPB *sy;

    /*
     * sy - points to sync parameter block for
     * which mutex is desired
     */
    sy = (SPB *) ls;
    if (tak_flag(sy))
        azombie(e, 0);
    else
        evinsert(e, &sy->sy_wait);
}


void unsync(SPB *sy)
{
    EVB *p;

    /* internal unsync must be in dispatcher context or NODISP */

    if (sy->sy_tas <= 0)        /* e.g. more wind_update(FALSE) */
    {                           /*  than wind_update(TRUE)      */
        sy->sy_tas = 0;
        return;
    }

    /* count down */
    sy->sy_tas--;

    /*
     * if it went to 0, then give up the sync
     * to the next guy (if there is one)
     */
    if (sy->sy_tas == 0)
    {
        if ((p = sy->sy_wait) != 0)
        {
            /* next off the wait list */
            sy->sy_wait = p->e_link;
            sy->sy_owner = p->e_pd;
            /* restart counting semaphore */
            sy->sy_tas = 1;
            azombie(p, 0);
            dsptch();
        }
        else
            sy->sy_owner = NULL;    /* reset owner field */
    }
}
