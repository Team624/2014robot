#include <Wire.h>
#include <Adafruit_NeoPixel.h>

#define PINA 5
#define PINB 6
#define PINC 7

Adafruit_NeoPixel driveStrip = Adafruit_NeoPixel(30, PINA, NEO_GRB + NEO_KHZ800); //Shows Drive State (omni, not omni)
Adafruit_NeoPixel stripA = Adafruit_NeoPixel(28, PINB, NEO_GRB + NEO_KHZ800); //Shows Shoot Cycle (rollers, hold ball, shoot ready, shooting)
Adafruit_NeoPixel stripC = Adafruit_NeoPixel(24, PINC, NEO_GRB + NEO_KHZ800); //Shows IR fieldpos and line detected

#include "utilities.h"
#include "animations.h"

Animation* animationDrive;
Animation* animationA;
Animation* animationC;


//The setup of most of the code
void setup()
{
	animationA = new Steady(stripA.Color(0,255,0),0,stripA);
	
	//animationA = new Pixelate(stripA.Color(0,255,0),stripA.Color(0,0,255),5,stripA);
	animationC = new FadePulse(stripC.Color(0,255,0),0,stripC);
	animationDrive = new FadePulse(driveStrip.Color(0,255,0),0,driveStrip);
	
	
	//animationA = new PixThree(stripA.Color(255,0,0),stripA.Color(255,255,255),stripA.Color(0,0,255),10,stripA);
	//animationC = new PixThree(stripC.Color(255,0,0),stripC.Color(255,255,255),stripC.Color(0,0,255),10,stripC);
	//animationDrive = new PixThree(driveStrip.Color(255,0,0),driveStrip.Color(255,255,255),driveStrip.Color(0,0,255),10,driveStrip);
	
	//animationC = new Pixelate(stripC.Color(0,255,0),stripC.Color(0,0,255),0,stripC);
	//animationDrive = new Pixelate(driveStrip.Color(0,255,0),driveStrip.Color(0,0,255),0,driveStrip);
	
	
	//animationA = new Rainbow(10,stripA);
	//nimationC = new Rainbow(10,stripC);
	//animationDrive = new Rainbow(10,driveStrip);
	
	
	pinMode(13,OUTPUT);
	pinMode(PINA,OUTPUT);
	pinMode(PINB,OUTPUT);
	pinMode(PINC,OUTPUT);

	stripA.begin();
	stripA.show();
	stripC.begin();
	stripC.show();
	driveStrip.begin();
	driveStrip.show();
	
}

void loop()
{
	delay(animationA->sleepTime);
	bool completed = animationA->update();
	delay(animationC->sleepTime);
	bool completedC = animationC->update();
	delay(animationDrive->sleepTime);
	bool completedD = animationDrive->update();
}