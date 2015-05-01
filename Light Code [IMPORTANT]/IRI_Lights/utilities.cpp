#include "utilities.h"
/* returns a color that is a position on a gradient from colorFrom to colorTo */
uint32_t gradientColor(uint32_t colorFrom, uint32_t colorTo, byte fadeAmount) {

  uint8_t fromR = (uint8_t)(colorFrom >> 16);
  uint8_t fromG = (uint8_t)(colorFrom >>  8);
  uint8_t fromB = (uint8_t)colorFrom;
  uint8_t toR = (uint8_t)(colorTo >> 16);
  uint8_t toG = (uint8_t)(colorTo >>  8);
  uint8_t toB = (uint8_t)colorTo;
  uint8_t r = map(fadeAmount, 0, 255, fromR, toR);
  uint8_t g = map(fadeAmount, 0, 255, fromG, toG);
  uint8_t b = map(fadeAmount, 0, 255, fromB, toB);
  return (r << 16) | (g << 8) | g;
}

/* fill the strip with a certain brightness at a certain color */
void fillStrip(uint32_t c, uint8_t brightness, Adafruit_NeoPixel& strip) {

  uint8_t r = (uint8_t)(c >> 16);
  uint8_t g = (uint8_t)(c >>  8);
  uint8_t b = (uint8_t)c;
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, (r * brightness / 255), (g * brightness / 255), (b * brightness / 255));
  } 
  //
 // strip.show();
}

void fillStrip(uint32_t c, Adafruit_NeoPixel& strip) {
  fillStrip(c, 255, strip); 
}

uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return makeColor(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return makeColor(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return makeColor(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

uint32_t makeColor(byte r, byte g, byte b) {
  return ((uint32_t)r << 16) | ((uint32_t)g << 8) | (uint32_t)b;
}

uint32_t lfsr = 0xbeefbeef;
uint8_t getRandomBit() {
  uint8_t b1 = (lfsr >> 30) & 0b1;
  uint8_t b2 = (lfsr >> 31) & 0b1;
  lfsr = lfsr << 1;
  lfsr |= b1 ^ b2;
  return (lfsr & 0b1);
}