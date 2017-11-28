#include "FastLED.h"

#define NUM_LEDS 1
#define DATA_PIN 3

// This is an array of leds.  One item for each led in your strip.
CRGB leds[NUM_LEDS];

// variables
int fade = 0;
int delayNumber = 500;

void setup() {
  // sanity check delay - allows reprogramming if accidently blowing power w/leds
  delay(2000);
  //LED type
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);

    
}

void loop() {

  leds[0] = CRGB::White;
  leds[0].fadeLightBy(fade);
  FastLED.show();
  delay(500);

  leds[0] = CRGB::Black;
  FastLED.show();
  delay(500);
  

}
