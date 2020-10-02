#include "flex.h"

namespace asrl = ardserial;

namespace flex
{
void read_sensors()
{
	int sensorValue5 = analogRead(A9);
	int sensorValue4 = analogRead(A8);
	int sensorValue3 = analogRead(A7);
	int sensorValue2 = analogRead(A6);
	int sensorValue1 = analogRead(A1);

	// convert the analog reading (which goes from 0 - 1023) to a max voltage (0 - 3.3V)
	const float CONVERSION_RATIO = (common::MAX_VOLTAGE / common::MAX_ANALOG_READING);
	float voltage5 = sensorValue5 * CONVERSION_RATIO;
	float voltage4 = sensorValue4 * CONVERSION_RATIO;
	float voltage3 = sensorValue3 * CONVERSION_RATIO;
	float voltage2 = sensorValue2 * CONVERSION_RATIO;
	float voltage1 = sensorValue1 * CONVERSION_RATIO;

	// print out the value you read
	asrl::printf("V1: %f\tV2: %f\tV3: %f\tV4: %f\tV5: %f", voltage1, voltage2, voltage3, voltage4, voltage5);
}
} // namespace flex