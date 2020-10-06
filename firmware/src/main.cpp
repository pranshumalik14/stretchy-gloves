#include "ardserial.h"
#include "bt.h"
#include "calibrate.h"
#include "constants.h"
#include "flex.h"
#include "fsm.h"
#include "imu.h"
#include <Arduino.h>

namespace asrl = ardserial;

void setup()
{
	Serial.begin(common::BAUD_RATE);
	analogReadResolution(common::ADC_RESOLUTION);
}

void loop()
{
	flex::read_sensors();
	delay(100);
}