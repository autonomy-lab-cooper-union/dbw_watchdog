#include <stdio.h>
#include <thread>
#include <unistd.h>
#include <vector>
#include "watchdog.h"
#include "test_estop.h"
#include "sample_task.h"
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
    printf("hello world\n");
    core::current_mode.store(core::modes::FULL_DRIVE);
    //printf("the current driving mode is %d\n", core::current_mode.load());
    //std::thread mod_test_estop (test_estop);
    //std::thread mod_sample_task (sample_task);
    threads.push_back(std::thread(sample_task));
    //printf("the current driving mode is %d\n", core::current_mode.load());

    int buffer[NUM_THREADS] = {0};
    
    for (;;) 
    {   
        buffer[0] = core::status[0].load();     
        usleep(100*1000); 
        if (buffer[0] == core::status[0].load()); 
        {
            printf("Stopped with buffer %d\n", buffer[0]);
            break;
        }
    }
    // when the program exits, ALL the threads die too
    exit(0);

}
