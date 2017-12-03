#include "FastLED.h"

#define NUM_LEDS 1
#define DATA_PIN 3

// This is an array of leds.  One item for each led in your strip.
CRGB leds[NUM_LEDS];
   
int sensor;           //Variable to store analog value (0-1023)

void setup()
{
  Serial.begin(9600);      //Only for debugging
  // sanity check delay - allows reprogramming if accidently blowing power w/leds
  delay(2000);
  //LED type
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
}

void loop() {
  
  sensor = analogRead(A2);
  //While sensor is not moving, analog pin receive 1023~1024 value
  if (sensor<600){
    leds[0] = CRGB::Black;
    Serial.print("Sensor Value: ");
    Serial.println(sensor);
    FastLED.show();

  }
  else{ 
    leds[0] = CRGB::White;
    Serial.print("Sensor Value: ");
    Serial.println(sensor);
    FastLED.show();
    delay(5000); //Small delay
  }
}
