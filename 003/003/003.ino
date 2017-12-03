#include "FastLED.h"
#include <Adafruit_NeoPixel.h>

//LEDs
#define NEO_PIN 2
#define NUM_LEDS 5

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_LEDS, NEO_PIN, NEO_GRB + NEO_KHZ800);

//Shake Switch
int sensor;           //Variable to store analog value (0-1023)



void setup()
{
  Serial.begin(9600);      //Only for debugging
  // sanity check delay - allows reprogramming if accidently blowing power w/leds
  delay(2000);
  //LED type
  //FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
  pixels.begin(); // This initializes the NeoPixel library.

}

void loop() {
  
  sensor = analogRead(A2);
  //While sensor is not moving, analog pin receive 1023~1024 value
  if (sensor<1023){
    Serial.print("Sensor Value: ");
    Serial.println(sensor);

    //leds
    for(int i=0;i<NUM_LEDS;i++){
      //delay(700); // Delay for a period of time (in milliseconds).
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      pixels.setPixelColor(i, pixels.Color(0,0,0)); // Moderately bright green color.
      pixels.show(); // This sends the updated pixel color to the hardware.
    }
    
  }
  else{ 
    Serial.print("Sensor Value: ");
    Serial.println(sensor);
    
    for(int i=0;i<NUM_LEDS;i++){
  
      // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
      pixels.setPixelColor(i, pixels.Color(255,255,255)); // Moderately bright red color.
      pixels.show(); // This sends the updated pixel color to the hardware.
    }
      delay(10000); // Delay for a period of time (in milliseconds).
    //FADE OFF
    for(int i=0;i<NUM_LEDS;i++){
      
      for(int val=255;val>0;val--){
      pixels.setPixelColor(i, pixels.Color(val,val,val)); // Moderately bright red color.
      pixels.show(); // This sends the updated pixel color to the hardware.
      }
      
    }
  }
  delay(50);
}
