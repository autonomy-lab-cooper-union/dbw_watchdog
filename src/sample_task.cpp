#include <stdio.h>
#include <unistd.h>
#include "core.h"
#include "sample_task.h"

// impl. functions in core to kick watchdog

#define THIS_THREAD 0

void sample_task()
{

    int count = 0;
    for (;;) 
    {
        core::status[THIS_THREAD]++;
         //printf("status %d\n", core::status[0].load());
        
        /* BLACK BOX */
        if (count >= 25) 
        {
            break;
        }
        //printf("Hello!\n");
        usleep(1000);
        count++;
        /* END BLACK BOX */
    }
}
