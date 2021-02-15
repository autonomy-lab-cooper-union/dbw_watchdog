#include <stdio.h>
#include <unistd.h>
#include "watchdog.h"
#include "sample_task3.h"

#define THIS_THREAD 3

void sample_task3()
{

    int count = 0;
    for (;;) 
    {
        core::status[THIS_THREAD]++;
         //printf("status %d\n", core::status[0].load());d()++;
        
        /* BLACK BOX */
        if (count >= 77) 
        {
            break;
        }
        //printf("hihihi(3)!\n");
        usleep(730);
        count++;
        /* END BLACK BOX */
    }
}
