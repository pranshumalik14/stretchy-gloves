#ifndef STRETCHY_GLOVES_FLEX_H
#define STRETCHY_GLOVES_FLEX_H
#include "ardserial.h"
#include "constants.h"

namespace flex
{
    double * read_sensors()
    {
    	int sensorValue5 = analogRead(A9); // pinky finger
    	int sensorValue4 = analogRead(A8); // middle finger
    	int sensorValue3 = analogRead(A7); // ring finger
    	int sensorValue2 = analogRead(A6); // thumb
    	int sensorValue1 = analogRead(A0); // index

    	const float CONVERSION_RATIO = (common::MAX_VOLTAGE / common::MAX_ANALOG_READING);

    	// convert the analog reading (which goes from 0 - 1023) to a max voltage (0 - 3.3V)
    	float voltage5 = static_cast<float>(sensorValue5) * CONVERSION_RATIO;
    	float voltage4 = static_cast<float>(sensorValue4) * CONVERSION_RATIO;
    	float voltage3 = static_cast<float>(sensorValue3) * CONVERSION_RATIO;
    	float voltage2 = static_cast<float>(sensorValue2) * CONVERSION_RATIO;
    	float voltage1 = static_cast<float>(sensorValue1) * CONVERSION_RATIO;

    	// print out the value you read
    	//ardserial::printf("V1: %f\tV2: %f\tV3: %f\tV4: %f\tV5: %f", voltage1, voltage2, voltage3, voltage4, voltage5);
    	double volts[5] = {voltage1, voltage2, voltage3, voltage4, voltage5};
    	return volts;
    }
} // namespace flex

#endif // STRETCHY_GLOVES_FLEX_H
