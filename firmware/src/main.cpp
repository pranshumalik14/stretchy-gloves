#include "ardserial.h"
#include "bt.h"
#include "calibrate.h"
#include "constants.h"
#include "flex.h"
#include "fsm.h"
#include "imu.h"
#include "monitor.h"

#include <Arduino.h>

#define RIGHT_HAND (true);

void setup()
{
	Serial.begin(common::BAUD_RATE);
	analogReadResolution(common::ADC_RESOLUTION);
	pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
	flex::read_sensors();
	digitalWriteFast(LED_BUILTIN, HIGH);
	delay(600); // 500 ms
	digitalWriteFast(LED_BUILTIN, LOW);
	delay(300); // 500 ms
}