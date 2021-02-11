#ifndef WATCHDOG_H
#define WATCHDOG_H

#define NUM_THREADS 4

#include <atomic>
#include <array>

int main();

namespace core 
{
    void estop();

    enum modes 
    {
        FULL_DRIVE,
        ONLY_STEERING,
        MANUAL,
        ESTOP
    };

    extern std::atomic<int> current_mode;
    //extern std::atomic<int> status;
    //extern std::atomic<std::array<int, NUM_THREADS>> status;
    extern std::array<std::atomic_int, NUM_THREADS> status;
}

#endif
