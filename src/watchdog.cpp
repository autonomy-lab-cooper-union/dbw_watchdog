#include <stdio.h>
#include "../include/watchdog.h"
#include "../include/test_estop.h"

enum modes {
    FULL_DRIVE,
    ONLY_STEERING,
    MANUAL,
    ESTOP
};

int current_mode;

int main() {
    printf("hello world\n");
    current_mode = modes::FULL_DRIVE;
    printf("the current driving mode is %d\n", current_mode);
    test_estop();
    printf("the current driving mode is %d\n", current_mode);
}

void estop() {
    current_mode = modes::ESTOP;
    printf("I am setting the mode to %d\n", current_mode);
}
