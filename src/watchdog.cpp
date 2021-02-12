#include <stdio.h>
#include <thread>
#include <unistd.h>
#include <vector>
#include "watchdog.h"
#include "test_estop.h"
#include "sample_task.h"
#include "sample_task1.h"
#include "sample_task2.h"
#include "sample_task3.h"
#include <atomic>

// I moved some stuff into a new "core" namespace
namespace core 
{
    std::array<std::atomic_int, NUM_THREADS> status;
    std::atomic_int current_mode (modes::FULL_DRIVE);
    void estop() 
    {
        current_mode = modes::ESTOP;
        printf("ESTOP! %d\n", current_mode.load());
    }
}

int main() 
{
    std::vector<std::thread> threads;
    core::current_mode.store(core::modes::FULL_DRIVE);
    //printf("the current driving mode is %d\n", core::current_mode.load());
    //std::thread mod_test_estop (test_estop);
    //std::thread mod_sample_task (sample_task);
    threads.push_back(std::thread(sample_task));
    threads.push_back(std::thread(sample_task1));
    threads.push_back(std::thread(sample_task2));  
    threads.push_back(std::thread(sample_task3));  
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
            printf("buffer: thread %d, Buffer Value: %d, Status Value: %d\n", i, buffer[i], core::status[i].load());
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
