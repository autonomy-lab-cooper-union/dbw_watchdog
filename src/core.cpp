#include <stdio.h>
#include <thread>
#include <unistd.h>
#include <vector>
#include "core.h"
#include <atomic>

namespace core 
{
    std::array<std::atomic<std::int64_t>, NUM_THREADS> status;
    std::atomic_int current_mode (modes::FULL_DRIVE);
    void estop() 
    {
        current_mode = modes::ESTOP;
        printf("ESTOP! %d\n", current_mode.load());
    }
}
