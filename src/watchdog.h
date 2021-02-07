#ifndef WATCHDOG_H
#define WATCHDOG_H

int main();

namespace core {
    void estop();

    enum modes {
        FULL_DRIVE,
        ONLY_STEERING,
        MANUAL,
        ESTOP
    };

    extern int current_mode;
}

#endif
