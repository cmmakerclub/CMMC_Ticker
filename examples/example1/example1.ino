#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <CMMC_Ticker.h>

uint8_t state = 0;
CMMC_Ticker ticker(&state, 200);

void setup()
{
    Serial.begin(57600);
    ticker.start();
}

void loop()
{ 
    Serial.println(state); 
    if (state == 1) {
        state = 0;
    }
    delay(100);
}
