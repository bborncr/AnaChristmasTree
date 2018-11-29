/**
 * Ana's Christmas LEDs
 * CRCibernetica 2018
*/

#include <FastLED.h>
#include "effect.h"

#define NUM_LEDS 20
#define DATA_PIN 4
#define CLOCK_PIN 7

#define FRAMES_PER_SECOND  120

CRGB leds[NUM_LEDS];

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

Effect effect1(FIRE, leds, 0, 5, 5);
Effect effect2(TV, leds, 6, 6, 15);
Effect effect3(STROBE, leds, 9, 19, 5);
Effect effect4(XMASTREE, leds, 7, 8);

void setup() {
  Serial.begin(9600);
  Serial.println("Starting...");
  //  LEDS.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(84);
}

void loop() {
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
