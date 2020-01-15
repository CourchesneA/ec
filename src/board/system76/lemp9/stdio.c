#include <stdio.h>

#ifdef SERIAL_DEBUGGER
    #include <mcs51/8051.h>
#endif

#ifdef I2C_DEBUGGER
    #include <ec/i2c.h>
#endif

int putchar(int c) {
    unsigned char byte = (unsigned char)c;
#ifdef SERIAL_DEBUGGER
    SBUF = byte;
#endif
#ifdef I2C_DEBUGGER
    i2c_send(&I2C_4, I2C_DEBUGGER, &byte, 1);
#endif
    return (int)byte;
}