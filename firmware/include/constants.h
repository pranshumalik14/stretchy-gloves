#ifndef STRETCHY_GLOVES_CONSTANTS_H
#define STRETCHY_GLOVES_CONSTANTS_H

namespace common
{
const long BAUD_RATE				  = 9600;					// bits per sec
const unsigned int ADC_RESOLUTION	  = 10;						// bits
const float MAX_VOLTAGE				  = 3.3f;					// 3.3V
const unsigned int MAX_ANALOG_READING = (1u << ADC_RESOLUTION); // 1 * 2^10
} // namespace common

#endif // STRETCHY_GLOVES_CONSTANTS_H
