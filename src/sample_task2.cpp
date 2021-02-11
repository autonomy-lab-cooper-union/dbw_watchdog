#include <stdio.h>
#include <unistd.h>
#include "watchdog.h"
#include "sample_task2.h"
void sample_task2()
{

    int count = 0;
    for (;;) 
    {
        core::status[THIS_THREAD]++;
         //printf("status %d\n", core::status[0].load());d()++;
        
        /* BLACK BOX */
        if (count >= 51) 
        {
            break;
        }
        //printf("Message(2)!\n");
        usleep(1220);
        count++;
        /* END BLACK BOX */
    }
}
