#include <stdio.h>
#include "core.h"
#include "mod_canhealth.h"

// impl. functions in core to kick watchdog

void mod_canhealth(const int THIS_THREAD)
{
    int count = 0;
    for (;;)
    {
        core::status[THIS_THREAD]++;
        usleep(1000);
        count++;
        /* END BLACK BOX */
    }
}
