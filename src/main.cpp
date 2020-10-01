#include <Arduino.h>
#include "bt.h"
#include "imu.h"
#include "flex.h"
#include "calibrate.h"
#include "ardserial.h"
#include "constants.h"
#include "fsm.h"

namespace asrl = ardserial;

void setup() {
    Serial.begin(common::BAUD_RATE);
    analogReadResolution(common::ADC_RESOLUTION);
}

void loop() {
    flex::read_sensors();
    delay(100); // 100 ms
}