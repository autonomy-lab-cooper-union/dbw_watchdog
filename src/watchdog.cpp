#include <stdio.h>
#include <thread>
#include <unistd.h>
#include <vector>
#include "watchdog.h"
#include "core.h"
#include "test_estop.h"
#include "sample_task.h"
#include "sample_task1.h"
#include "sample_task2.h"
#include "sample_task3.h"
#include <atomic>

void (*modules[])()
{
    sample_task,
    sample_task1,
    sample_task2,
    sample_task3
};

int main() 
{
    std::vector<std::thread> threads;
    core::current_mode.store(core::modes::FULL_DRIVE);
    //printf("the current driving mode is %d\n", core::current_mode.load());
    //std::thread mod_test_estop (test_estop);
    //std::thread mod_sample_task (sample_task);
    for (auto& task : modules) {
        threads.push_back(std::thread(task));
    }
    //printf("the current driving mode is %d\n", core::current_mode.load());

    int buffer[NUM_THREADS] = {0};
    int leave = 0;
    
    for (;;) 
    {   
        for(int i=0; i < NUM_THREADS; ++i) {
            buffer[i] = core::status[i].load();
            //printf("buffer: index %d, Value: %d\n", i, buffer[i]);
        }

        usleep(100 * 1000);

        for(int i=0; i < NUM_THREADS; ++i) {
            printf("buffer: thread %d, Buffer Value: %d, Status Value: %ld\n", i, buffer[i], core::status[i].load());
            if (buffer[i] == core::status[i].load()) {
                printf("Stopped due to thread %d\n", i);
                goto exit;
            }
        }
    }
exit:
    // when the program exits, ALL the threads die too
    exit(0);
}
