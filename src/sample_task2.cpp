#include <stdio.h>
#include <unistd.h>
#include "core.h"
#include "sample_task2.h"

#define THIS_THREAD 2

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
