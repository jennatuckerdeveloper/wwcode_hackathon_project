
#include <Arduino.h>
#define USE_SERIAL Serial


int sensorPin = A0;    // select the input pin for the potentiometer

int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  USE_SERIAL.begin(115200);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  USE_SERIAL.println(sensorValue);
  delay(2000);
}
