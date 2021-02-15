#include <stdio.h>
#include <unistd.h>
#include "watchdog.h"
#include "sample_task1.h"

#define THIS_THREAD 1

void sample_task1()
{

    int count = 0;
    for (;;) 
    {
        core::status[THIS_THREAD]++;
         //printf("status %d\n", core::status[0].load());d()++;
        
        /* BLACK BOX */
        if (count >= 62) 
        {
            break;
        }
        //printf("Test(1)!\n");
        usleep(800);
        count++;
        /* END BLACK BOX */
    }
}
