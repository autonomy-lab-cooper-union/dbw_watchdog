#include <stdio.h>
#include <thread>
#include <unistd.h>
#include <vector>
#include "watchdog.h"
#include "test_estop.h"

// I moved some stuff into a new "core" namespace
namespace core {
    void estop() {
        current_mode = modes::ESTOP;
        printf("ESTOP! %d\n", current_mode);
    }
}

int main() {
    printf("hello world\n");
    core::current_mode = core::modes::FULL_DRIVE;
    printf("the current driving mode is %d\n", core::current_mode);
    std::thread mod_test_estop (test_estop);
    printf("the current driving mode is %d\n", core::current_mode);
    for (;;) {
        sleep(1); 
    }

}
