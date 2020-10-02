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

	const float CONVERSION_RATIO = (common::MAX_VOLTAGE / common::MAX_ANALOG_READING);

	// convert the analog reading (which goes from 0 - 1023) to a max voltage (0 - 3.3V)
	float voltage5 = static_cast<float>(sensorValue5) * CONVERSION_RATIO;
	float voltage4 = static_cast<float>(sensorValue4) * CONVERSION_RATIO;
	float voltage3 = static_cast<float>(sensorValue3) * CONVERSION_RATIO;
	float voltage2 = static_cast<float>(sensorValue2) * CONVERSION_RATIO;
	float voltage1 = static_cast<float>(sensorValue1) * CONVERSION_RATIO;

	// print out the value you read
	asrl::printf("V1: %f\tV2: %f\tV3: %f\tV4: %f\tV5: %f", voltage1, voltage2, voltage3, voltage4, voltage5);
}
} // namespace flex