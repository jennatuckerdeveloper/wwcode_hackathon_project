#include <Arduino.h>
#define USE_SERIAL Serial
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"


Adafruit_8x16matrix matrix = Adafruit_8x16matrix();

int sensorPin = A0;    // select the input pin for the potentiometer

int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  USE_SERIAL.begin(115200);

  // set up LED matrix and clear any previous display
  matrix.begin(0x70);  
  matrix.clear();
  matrix.writeDisplay();
}



// draw frowny face
static const uint8_t PROGMEM
frown_bmp[] =
{ B00111100,
  B01000010,
  B10100101,
  B10000001,
  B10011001,
  B10100101,
  B01000010,
  B00111100
};



void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  USE_SERIAL.println(sensorValue);
  delay(500);

  //if spoiled food is detected, blink
  if (sensorValue > 400) {
    USE_SERIAL.println("hey eat me");
    matrix.drawBitmap(0, 0, frown_bmp, 8, 8, LED_ON);
    matrix.writeDisplay();
    matrix.blinkRate(2);
    delay(500);

  }

  else {
    USE_SERIAL.println("all good");
    matrix.clear();
    matrix.writeDisplay();
  }
}



