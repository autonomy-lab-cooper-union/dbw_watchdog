#include <net/if.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "core.h"
#include "mod_canifstate.h"

// impl. functions in core to kick watchdog

void mod_canifstate(const int THIS_THREAD)
{
    LOGMSG(mod_canifstate, 0, "initializing...");
    int count = 0;
    // set up stuff for ioctl
    struct ifreq ifr;
    strncpy(ifr.ifr_name, "can0", IFNAMSIZ);
    ifr.ifr_flags = IFF_UP|IFF_RUNNING|IFF_NOARP;
    int fd = socket(AF_UNIX, SOCK_DGRAM, 0);
    LOGMSG(mod_canifstate, 0, "initialized; running");
    for (;;)
    {
        if (int r = ioctl(fd, SIOCGIFFLAGS, &ifr) < 0) {
                LOGMSG(mod_canifstate, 1, "Error in ioctl! Error %d: %s", r, strerror(r));
                //fprintf(stderr, MSGSTART(mod_canifstate, 1) "Error in ioctl! Error %d: %s\n", r, strerror(r));
                return;
        }
        // printf("interface is up: %d\n", (ifr.ifr_flags & IFF_UP));

        if (!(ifr.ifr_flags & IFF_UP)) {
            LOGMSG(mod_canifstate, 1, "CAN UNHEALTHY, calling estop()");
            core::estop();
        }
        core::status[THIS_THREAD]++;
        usleep(1000);
        count++;
    }
}
