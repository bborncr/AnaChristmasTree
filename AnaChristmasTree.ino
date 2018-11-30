/**
 * Ana's Christmas LEDs
 * CRCibernetica 2018
*/

#include <FastLED.h>
#include "effect.h"

#define FRAMES_PER_SECOND  120

CRGB leds[20];
CRGB leds2[50];

enum modes {
  FIRE,
  TV,
  XMASTREE,
  STROBE
};

/*
 * Effect myEffect(mode, FastLED Object, start led, end led, frame count);
 * Default frame count = 20
*/

//Effect effect1(FIRE, leds, 0, 5, 5);
//Effect effect2(TV, leds, 6, 6, 15);
//Effect effect3(STROBE, leds, 9, 19, 5);
//Effect effect4(XMASTREE, leds, 7, 8);

Effect effect1(FIRE, leds, 2, 2, 5);
Effect effect2(TV, leds, 3, 3, 15);
Effect effect3(XMASTREE, leds, 5, 5);

Effect effect4(FIRE, leds2, 0, 49, 5);

void setup() {
  Serial.begin(9600);
  Serial.println("Starting...");
  FastLED.addLeds<WS2812, 13, RGB>(leds2, 50);
  FastLED.addLeds<WS2801, 4, 7, RGB>(leds, 20);
  FastLED.setBrightness(84);
}

void loop() {
  leds[8] = CHSV(64, 255, 200);
  updateAll();
  FastLED.show();
  FastLED.delay(1000 / FRAMES_PER_SECOND);
}

void updateAll() {
  effect1.Update();
  effect2.Update();
  effect3.Update();
  effect4.Update();
}
