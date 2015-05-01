#include <Arduino.h>
#include <Wire.h>

#include "IRILights.h"
#include "packets.h"
#include "animations.h"
#include "utilities.h"

#define PINS 5
#define PINF 6
#define PINB 7

//Globals
//Adafruit_NeoPixel left = Adafruit_NeoPixel(30, PINL, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel side = Adafruit_NeoPixel(30, PINS, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel front = Adafruit_NeoPixel(28, PINF, NEO_GRB + NEO_KHZ800); 
Adafruit_NeoPixel back = Adafruit_NeoPixel(24, PINB, NEO_GRB + NEO_KHZ800);
unsigned long counter = 0; 

//The setup of most of the code
void setup()
{	
	//pinMode(PINL,OUTPUT);
	pinMode(PINS,OUTPUT);
	pinMode(PINF,OUTPUT);
	pinMode(PINB,OUTPUT);
	Wire.onReceive(readPacket);
	Wire.begin(2); //address
  	
//	left.begin();
//	left.show();
	
//	right.begin();
//	right.show();
	side.begin();
	side.show();
	
	front.begin();
	front.show();
  
  back.begin();
  back.show();
	
}

void loop()
{
	counter++;
  delay(20);
  if(gameState == MODE_TELEOP) {
    indicators();
  } else if (gameState == MODE_DISABLED) {
    //orbit(makeColor(0,255,0));
	//	fade(makeColor(0,255,0));
	//pixelBootUp(makeColor(0, 255, 0), makeColor(0,32,0));
scanner(makeColor(0,255,0));
	//colorSlide(makeColor(255,0,0), makeColor(255, 255, 255), makeColor(0, 0, 0));
	//rainbow();
  } else if (gameState == MODE_AUTO) {
    if(alliance == BLUE_ALLIANCE) {
      scanner(makeColor(0,0,255));
    } else {
      scanner(makeColor(255, 0, 0));
    }
  } else {
    //fade(makeColor(255,0,0));
    //rainbow();
    //pixelBootUp(makeColor(0, 255, 0), makeColor(255,255,255));
	rainbow();
  }
 // left.show();
//  right.show();
	side.show();
  front.show();
  back.show();
}

//Animations