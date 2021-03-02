#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "core.h"
#include "mod_canhealth_lsc.h"
#include "libsocketcan.h"

// impl. functions in core to kick watchdog

void mod_canhealth_lsc(const int THIS_THREAD)
{
    int* canState = 0;
    int count = 0;
    LOGMSG(mod_canhealth, 0, "Running");
    for (;;)
    {
        
        if (can_get_state("can0", canState) == -1) {
            LOGMSG(mod_canhealth, 1, "CAN UNHEALTHY, calling estop()");
            core::estop();
        }
        core::status[THIS_THREAD]++;
        usleep(1000);
        count++;
    }
}
