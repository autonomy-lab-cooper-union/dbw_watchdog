#include <stdio.h>
#include <unistd.h>
#include "watchdog.h"
#include "sample_task.h"
void sample_task()
{

    int count = 0;
    for (;;) 
    {
        core::status[THIS_THREAD].load();
        /* BLACK BOX */
        if (count >= 15) 
        {
            break;
        }
        printf("Hello!\n");
        usleep(1000);
        count++;
        /* END BLACK BOX */
    }
}
