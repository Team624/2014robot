#include <Wire.h>
#include <Adafruit_NeoPixel.h>

#include "utilities.h"
#include "packets.h"
#include "animations.h"

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(160, PIN, NEO_GRB + NEO_KHZ800);

Animation* animation;

//The setup of most of the code
void setup()
{
	animation = new 
	pinMode(13,OUTPUT);
	pinMode(6,OUTPUT);
	Serial.begin(115200);
	Wire.onReceive(getPackets);
	Wire.begin(2);
	strip.begin();
	strip.show();
}

void setAnimation()
{
	delete animation;
	
	if(gameState == MODE_DISABLED)
	{
		animation = new FadePulse(strip.Color(0, 255,0), 0);
	}
	else if(gameState == MODE_AUTO)
	{
		if(alliance == RED_ALLIANCE)
		{
			animation = new Pixelate(strip.Color(255,0,0),0);
		}
		else if(alliance == BLUE_ALLIANCE)
		{
			animation = new Pixelate(strip.Color(0,0,255),0);
		}
		else
		{
			animation = new Pixelate(strip.Color(255,255,255),0);
		}
	}
	else if(gameState == MODE_TELEOP)
	{
		if(gear == HIGH_GEAR)
		{
			animation = new Steady(strip.Color(0,255,0), 0);
		}
		else
		{
			animation = new Steady(strip.Color(0,0,255), 0);
		}
		
		if(omni==1)
		{
			animation = new Omni(strip.Color(0,255,0), 0);
		}
		else
		{
			animation = new Stripes(strip.Color(0,255,0), strip.Color(255,255,255), 0);
		}
		
		if(robotState == STATE_SHOOT_READY)
		{
			animation = new Strobes(strip.Color(0,0,0), strip.Color(0,0,255), 20, 2);
		}
		else if(robotState == STATE_SHOOTING)
		{
			animation = new ColorRay(strip.Color(0,255,0), 0);
		}
		else if(robotState == STATE_ROLLING)
		{
			animation = new Pixelate(strip.Color(0,255,0);
		}
		else if(robotState == STATE_PASSING)
		{
			animation = new Bounce(strip.Color(0,255,0), 0);
		}
		else
		{
			animation = new Steady(strip.Color(0,255,0), 0);
		}
		
		if(linefound == 1)
		{
			animation = new Steady(strip.Color(255,0,0), 0);
		}
	}
	else
	{
		animation = new FadePulse(strip.Color(255,255,255), 0);
	}
}

void loop()
{
	delay(animation->sleepTime);
	bool completed = animation->update();
	if(completed || newData)
	{
		chooseAnimation();
		newData = false;
	}
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t cWheel(byte cWheelPos) {
  if(cWheelPos < 85) {
    return strip.Color(cWheelPos * 3, 255 - cWheelPos * 3, 0);
  } 
  else if(cWheelPos < 170) {
    cWheelPos -= 85;
    return strip.Color(255 - cWheelPos * 3, 0, cWheelPos * 3);
  } 
  else {
    cWheelPos -= 170;
    return strip.Color(0, cWheelPos * 3, 255 - cWheelPos * 3);
  }
}