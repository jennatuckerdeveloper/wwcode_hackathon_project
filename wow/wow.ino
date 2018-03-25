#include <Arduino.h>
#define USE_SERIAL Serial
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include "config.h"

#include <ESP8266HTTPClient.h>

#define USE_SERIAL Serial

unsigned long lastTime = 0;
unsigned long currentTime;
String payload;
int digit;
int httpCode;
int count = 0;

ESP8266WiFiMulti WiFiMulti;
#include "Adafruit_LEDBackpack.h"

AdafruitIO_Feed *gas = io.feed("Food Waste Gas Feed");

Adafruit_8x16matrix matrix = Adafruit_8x16matrix();
Adafruit_AlphaNum4 alpha4 = Adafruit_AlphaNum4();

int sensorPin = A0;    // select the input pin for the potentiometer

int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  USE_SERIAL.begin(115200);

  // set up LED matrix and clear any previous display
  matrix.begin(0x70);
  alpha4.begin(0x71);
  matrix.clear();
  alpha4.clear();
  matrix.writeDisplay();
  alpha4.writeDisplay();

  for(uint8_t t = 4; t > 0; t--) {
        USE_SERIAL.printf("[SETUP] WAIT %d...\n", t);
        USE_SERIAL.flush();
        delay(1000);
}
  io.connect();
  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(WIFI_SSID, WIFI_PASS);

}



// draw frowny face
static const uint8_t PROGMEM
frown_bmp[] =
{ B00111100,
  B01000010,
  B10100101,
  B10011001,
  B10000001,
  B10100101,
  B01000010,
  B00111100
};



void loop() {
  io.run();
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  USE_SERIAL.println(sensorValue);

  if (count++ > 2) {
    gas->save(sensorValue);
    count = 0;
  }



  if (sensorValue > 400) {
    USE_SERIAL.println("hey eat me");
    matrix.drawBitmap(0, 0, frown_bmp, 8, 8, LED_ON);
    matrix.writeDisplay();
    matrix.blinkRate(2);

    if((WiFiMulti.run() == WL_CONNECTED)) {
      textAlert();
    }
  }

  else {
    USE_SERIAL.println("all good");
    matrix.clear();
    matrix.writeDisplay();
  }
  
  for (int i = 0; i < 4; i++) {
    digit = (int) sensorValue / pow(10, 3-i);
    sensorValue -= digit * pow(10, 3-i);
    alpha4.writeDigitAscii(i, '0' + digit);
  }

  alpha4.writeDisplay();
  

  //if spoiled food is detected, blink
  
  
  
  delay(300);
}

void textAlert() {
        currentTime = millis() - lastTime;
        lastTime = millis();
        if (currentTime < 10000) {
          return;
        }
        HTTPClient http;
        http.begin("http://ec2-54-191-196-44.us-west-2.compute.amazonaws.com:3000/notify/"); //HTTP

        USE_SERIAL.print("[HTTP] GET...\n");
        // start connection and send HTTP header
        httpCode = http.GET();

        // httpCode will be negative on error
        if(httpCode > 0) {
            // HTTP header has been send and Server response header has been handled
            USE_SERIAL.printf("[HTTP] GET... code: %d\n", httpCode);

            // file found at server
            if(httpCode == HTTP_CODE_OK) {
                payload = http.getString();
                USE_SERIAL.println(payload);
            }
        } else {
            USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();
}





