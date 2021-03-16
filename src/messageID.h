#ifndef MESSAGE_ID_H
#define MESSAGE_ID_H

//if (rx_frame.MsgID >= ESTOP_RANGE_START && rx_frame.MsgID <= ESTOP_RANGE_END) set queue to canToEStop
//0x00000000
//0x10000000
//0x_____
enum canmsg_ID  {
    ADMIN_RANGE_START   = 0x00000,
    ADMIN_RANGE_END     = 0x003FF,
    ESTOP_RANGE_START   = 0x00400,
        MSG_ESTOP,
    ESTOP_RANGE_END     = 0x007FF,
    HOUSE_RANGE_START   = 0x00800,
    HOUSE_RANGE_END     = 0x00BFF,
    WATCH_RANGE_START   = 0x00C00,
    WATCH_RANGE_END     = 0x00FFF,
    BRK_RANGE_START     = 0x01000,
    BRK_RANGE_END       = 0x02FFF,
    STR_RANGE_START     = 0x03000,
    STR_RANGE_END       = 0x04FFF,
    SPD_RANGE_START     = 0x05000,
    SPD_RANGE_END       = 0x06FFF,
    MSC_RANGE_START     = 0x07000,
    MSC_RANGE_END       = 0x08FFF,
//For watchdog canmsgs :>
    FULL_DRIVE_START    = 0x09000, 
    FULL_DRIVE_END      = 0x0CFFF,
    ONLY_STEERING_START = 0x0D000,
    ONLY_STEERING_END   = 0x10FFF,
    MANUAL_START        = 0x11000,
    MANUAL_END          = 0x14FFF
};

#endif