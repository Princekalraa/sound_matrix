#include <FastLED.h>

#define NUM_LEDS 64
#define DATA_PIN 6
#define CLOCK_PIN 7

const int soundPin = A0;

CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, BGR>(leds, NUM_LEDS);
  FastLED.setBrightness(100);
}

void loop() {
  int soundValue = analogRead(soundPin);
  int brightness = map(soundValue, 0, 1023, 0, 255);
  
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(brightness, brightness, brightness);
  }
  
  FastLED.show();
  
  Serial.println(soundValue);
  
  delay(10);
}
