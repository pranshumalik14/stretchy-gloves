#ifndef STRETCHY_GLOVES_FLEX_H
#define STRETCHY_GLOVES_FLEX_H

#include "Arduino.h"
#include "ardserial.h"
#include "constants.h"

namespace flex
{
// TODO: accept sensor list from a user-friendly name to then read-out in an array/vector (see if stl supported)
void read_sensors();

// current/latest finger values

} // namespace flex

#endif // STRETCHY_GLOVES_FLEX_H
