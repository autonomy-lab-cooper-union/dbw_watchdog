#ifndef CORE_H
#define CORE_H

#include <atomic>
#include <array>

#define NUM_THREADS 4

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
    extern std::array<std::atomic<std::int64_t>, NUM_THREADS> status;
}


#endif