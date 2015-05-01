#ifndef UTILITIES_H
#define UTILITIES_H

#include <Adafruit_NeoPixel.h>

uint32_t gradientColor(uint32_t colorFrom, uint32_t colorTo, byte fadeAmount);

/* fill the strip with a certain brightness at a certain color */
void fillStrip(uint32_t c, uint8_t brightness, Adafruit_NeoPixel& strip);

/* use max brightness */
void fillStrip(uint32_t c, Adafruit_NeoPixel& strip);

/*Hue -> RGB color (useful for rainbow) */
uint32_t Wheel(byte WheelPos);

uint32_t makeColor(byte r, byte g, byte b);


uint8_t getRandomBit();

#endif /* UTILITIES_H*/