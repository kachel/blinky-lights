// This #include statement was automatically added by the Particle IDE.
#include "neopixel.h
#include "Particle.h"


SYSTEM_MODE(AUTOMATIC); // SYSTEM_MODE(AUTOMATIC) does not need to be called, because it is the default state; however the user can invoke this method to make the mode explicit.

// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_COUNT 24
#define PIXEL_PIN D6
#define PIXEL_TYPE WS2812B
#define BRIGHTNESS 25


    // Change These Variables
    int maxBrightness = 140;
    int minBrightness = 50;
    int fadeSpeed = 15;

    void setup() {
      strip.begin();
      strip.show(); // Initialize all pixels to 'off'

    }

    void loop() {

      //Set the color with Red, Gree, Blue values
      pulseColor(strip.Color(255, 0, 0), fadeSpeed);
      pulseColor(strip.Color(0, 0, 255), fadeSpeed);
    }


    void pulseColor(uint32_t c, uint8_t wait) {
      //Increase Brightness / Fade In
      for(int i=minBrightness; i<maxBrightness; i++) {
          strip.setBrightness(i);
          for(int x=0; x<strip.numPixels(); x++){
            strip.setPixelColor(x,c);
          }
          strip.show();
          delay(wait);
      }
      //Lower Brightness / Fade Out
      for(int i=maxBrightness; i>minBrightness; i--) {
           strip.setBrightness(i);
          for(int x=0; x<strip.numPixels(); x++){
            strip.setPixelColor(x,c);
          }
          strip.show();
          delay(wait);
      }
    }
