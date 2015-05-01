#include "animations.h"
#include "packets.h"
#include "utilities.h"
/*void orbit(uint32_t color)
{
	//right = 0 - ~30
	//front = ~30 - ~60
	//left = ~60 - ~90
	//back = ~90 - ~120

	unsigned long c = counter;
	c /= 5; //change this number to change speed
	
	int rl = right.numPixels();
	int ll = left.numPixels();
	int fl = front.numPixels();
	int bl = back.numPixels();
	
	int total = rl+ll+fl+bl;
	
	byte r = (byte)(color >> 16);
  byte g = (byte)(color >>  8);
  byte b = (byte) color;
	
  byte pulsePos = c % total;
  
	for(uint8_t i=0; i<total; ++i) //this /could/ be optimized. change div to bitshifts, etc
	{
		uint8_t divisor = 0;
		byte distance = abs(i - pulsePos); //straight dist
    byte altDistance = abs(total - pulsePos + i); //dist around strip
    if(altDistance < distance) distance = altDistance; //wrap around
		if      (distance <= 2) divisor = 1;
		else if (distance <= 4) divisor = 2;
		else if (distance <= 6) divisor = 4;
		else if (distance <= 8) divisor = 8;
		else divisor = 16; 
		right.setPixelColor(i, r/divisor, g/divisor, b/divisor);
		front.setPixelColor(i-30, r/divisor, g/divisor, b/divisor);
		left.setPixelColor(i-60, r/divisor, g/divisor, b/divisor);
		back.setPixelColor(i-90, r/divisor, g/divisor, b/divisor);
	}
	
}*/


void fade(uint32_t color) {
  byte brightness = counter;
  brightness = 255 - brightness;

  fillStrip(color, brightness, side);
  fillStrip(color, brightness, front);
  fillStrip(color, brightness, back);
}

void rainbow() {
  byte hueStart = counter; //downcast, overflows.
//  byte rl = right.numPixels();
//	byte ll = left.numPixels();
byte sl = side.numPixels();
	byte fl = front.numPixels();
	byte bl = back.numPixels();
  
  for(byte i=0; i<sl; i++) {
    side.setPixelColor(i, Wheel((hueStart + i)*4));
  }
  for(byte i=0; i<fl; i++) {
    front.setPixelColor(i, Wheel((hueStart + i)*4));
  }
  for(byte i=0; i<bl; i++) {
    back.setPixelColor(i, Wheel((hueStart + i)*4));
  }
}

void indicatorifyOneStrip(Adafruit_NeoPixel& strip) {
  unsigned long shootTime = counter - shootStartTime;
  byte len = strip.numPixels();
  byte firstDiv = len / 3;
  byte secondDiv;
  if(shootTime <= 30) {
    secondDiv = (len / 3) * 2 - ((byte) shootTime); //expand shoot bar
  } else {
    secondDiv = (len / 3) * 2;
  }
  uint32_t color1 = (gear == LOW_GEAR) ? makeColor(0, 0, 255) : makeColor (0, 255, 0);
  uint32_t color2;
  if(omni == OMNI_TRACTION) {
    color2 = makeColor(255, 0, 0);
  } else if (omni == OMNI_SWAGROLL) {
    color2 = makeColor(120, 0, 255);
  } else {
    color2 = 0; //black
  }
  uint32_t color3 = robotState == STATE_SHOOT_READY ? makeColor(255,255,255) : makeColor(0,0,0);
  if(robotState == STATE_UNKNOWN) {
    color3 = makeColor(0,0,0);
  } else if (robotState == STATE_SHOOT_READY) {
    color3 = makeColor(255,255,255);
  } else if (robotState == STATE_SHOOTING) {
    color3 = makeColor(255,255,255);
  } else if (robotState == STATE_SOFT_SHOOT) {
    color3 = makeColor(30, 255, 30); //light blue
  } else if (robotState == STATE_TOSS) {
    color3 = makeColor(255,200, 0); //orange
  }
  
 if(shootTime <= 60) {
	color3 = makeColor(0,255,0);
	
 }
  for(byte i=0; i < firstDiv; i++) {
    strip.setPixelColor(i, color1);
  } 
  for(byte i=firstDiv; i<secondDiv; i++) {
    strip.setPixelColor(i, color2);
  } 
  for(byte i=secondDiv; i<len; i++) {
    strip.setPixelColor(i, color3);
  }
}

void indicators() {
 // indicatorifyOneStrip(left);
 // indicatorifyOneStrip(right);
 indicatorifyOneStrip(side);
  indicatorifyOneStrip(front);
  indicatorifyOneStrip(back);
}

void scannerOneStrip(Adafruit_NeoPixel& strip, uint32_t color) {
  byte r = color >> 16;
  byte g = color >> 8;
  byte b = color;
  byte len = strip.numPixels();
  byte pulseHead = (counter % (len + 40));
  for(byte i = 0; i < len; i++) {
    uint8_t divisor = 0;
		int16_t distance = abs(i - pulseHead + 20); //straight dist
		if      (distance <= 2) divisor = 1;
		else if (distance <= 4) divisor = 2;
		else if (distance <= 5) divisor = 3;
		else if (distance <= 6) divisor = 4;
		else if (distance <= 7) divisor = 5;
		else if (distance <= 8) divisor = 6;
		else if (distance <= 9) divisor = 7;
		else if (distance <= 10) divisor = 8;
		else divisor = 16; 
		strip.setPixelColor(i, r/divisor, g/divisor, b/divisor);
  }
} 

void scanner(uint32_t color) {
 // scannerOneStrip(left, color);
//  scannerOneStrip(right, color);
scannerOneStrip(side, color);
  scannerOneStrip(front, color);
  scannerOneStrip(back, color);
}

void pixelBootUpOneStrip(Adafruit_NeoPixel& strip, uint32_t color1, uint32_t color2) {
  uint8_t numPixelsToFill = counter / 16;
  uint8_t len = strip.numPixels();
  uint8_t halfLen = len/2;
  
  if(counter % 2 == 0) {
	  for(byte i = 0; i < numPixelsToFill; i++) {
		strip.setPixelColor(halfLen + i, getRandomBit() ? color1 : color2);
		strip.setPixelColor(halfLen - i, getRandomBit() ? color1 : color2);
	  }
	}
}

void pixelBootUp(uint32_t color1, uint32_t color2) {
 pixelBootUpOneStrip(side, color1, color2);
  pixelBootUpOneStrip(front, color1, color2);
  pixelBootUpOneStrip(back, color1, color2);
}

void CSOne(Adafruit_NeoPixel& strip, uint32_t color1, uint32_t color2, uint32_t color3) {
	byte c = counter % 100;
	for(byte i = 0; i < strip.numPixels(); i++) {
		if((i + c) % 100 <= (33)) {
			strip.setPixelColor(i, color1);
		} else if ( (i + c) % 100 <= 66) {
			strip.setPixelColor(i, color2);
		} else {
			strip.setPixelColor(i, color3);
		}
	}
}

void colorSlide(uint32_t color1, uint32_t color2, uint32_t color3) {
	CSOne(front, color1, color2, color3);
	CSOne(side, color1, color2, color3);
	CSOne(back, color1, color2, color3);
}




