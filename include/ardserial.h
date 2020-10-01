#ifndef STRETCHY_GLOVES_ARDSERIAL_H
#define STRETCHY_GLOVES_ARDSERIAL_H

#include <Arduino.h>
#include <cstdarg>

// custom arduino serial commands
namespace ardserial {
#define ARDBUFFER 16        // buffer length in printf after which output flushed into Serial.print()

    int printf(char *str, ...); // c-style printf for printing multiple variables in one line over Arduino Serial
} // ardserial

#endif //STRETCHY_GLOVES_ARDSERIAL_H
