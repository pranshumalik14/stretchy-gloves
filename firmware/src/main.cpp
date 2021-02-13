#include "ardserial.h"
#include "bt.h"
#include "calibrate.h"
#include "constants.h"
#include "flex.h"
#include "fsm.h"
#include "imu.h"
#include "monitor.h"

#include <Arduino.h>
#define RIGHT_HAND(true) ;

namespace asrl = ardserial;

#include <SPI.h>
#include <TeensyView.h> // Include the SFE_TeensyView library

///////////////////////////////////
// TeensyView Object Declaration //
///////////////////////////////////
// Standard
#define PIN_RESET 15
#define PIN_DC    5
#define PIN_CS    10
#define PIN_SCK   13
#define PIN_MOSI  11

// Alternate (Audio)
//#define PIN_RESET 2
//#define PIN_DC    21
//#define PIN_CS    20
//#define PIN_SCK   14
//#define PIN_MOSI  7

TeensyView oled(PIN_RESET, PIN_DC, PIN_CS, PIN_SCK, PIN_MOSI);

void setup()
{
    Serial.begin(common::BAUD_RATE);
    analogReadResolution(common::ADC_RESOLUTION);
    oled.begin();     // Initialize the OLED
    oled.clear(ALL);  // Clear the display's internal memory
    oled.display();   // Display what's in the buffer (splashscreen)
    delay(1000);      // Delay 1000 ms
    oled.clear(PAGE); // Clear the buffer.
}

void loop()
{
    flex::read_sensors();
    oled.clear(PAGE); // Clear the page

    oled.rect(5, 5, 20, 20);         // Draw a rectangle
    oled.rectFill(35, 16, 23, 11);   // Draw a filled rectangle
    oled.circle(22, 20, 7);          // Draw the circle:
    oled.pixel(40, 7, WHITE, NORM);  // Draw a white pixel
    oled.pixel(48, 21, BLACK, NORM); // Draw a black pixel (on the above rectange)

    oled.setFontType(1);    // Set font to type 1
    oled.setCursor(73, 17); // move cursor
    oled.print("world!");   // Write a byte out as a character
    oled.setFontType(0);    // Set font to type 0
    oled.setCursor(67, 12); // move cursor
    oled.print("Hello");    // Write a byte out as a character

    oled.display(); // Send the PAGE to the OLED memory
    delay(100);
}