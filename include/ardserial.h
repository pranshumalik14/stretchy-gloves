#ifndef STRETCHY_GLOVES_ARDSERIAL_H
#define STRETCHY_GLOVES_ARDSERIAL_H

#include <Arduino.h>
#include <cstdarg>

// custom arduino serial commands
namespace ardserial
{
// buffer length in printf after which output flushed into Serial.print()
const size_t ARDBUFFER = 16;

// c-style printf for printing multiple variables in one line over Arduino Serial
int printf(char *str, ...);
} // namespace ardserial

#endif // STRETCHY_GLOVES_ARDSERIAL_H
