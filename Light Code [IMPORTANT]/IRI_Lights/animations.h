#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#include <Adafruit_NeoPixel.h>

extern Adafruit_NeoPixel side;
extern Adafruit_NeoPixel front;
extern Adafruit_NeoPixel back;
extern unsigned long counter;

//void pixelate();
void orbit(uint32_t color);
void fade(uint32_t color);
//void bounce();
void rainbow();
//void usa();
void indicators();
void scanner(uint32_t color);
void pixelBootUp(uint32_t color1, uint32_t color2);
void colorSlide(uint32_t color1, uint32_t color2, uint32_t color3);
#endif