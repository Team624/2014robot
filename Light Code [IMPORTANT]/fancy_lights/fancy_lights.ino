//4-17-14
#include <Wire.h>
#include <Adafruit_NeoPixel.h>

#define PINA 5
#define PINB 6
#define PINC 7

Adafruit_NeoPixel driveStrip = Adafruit_NeoPixel(30, PINA, NEO_GRB + NEO_KHZ800); //Shows Drive State (omni, not omni)
Adafruit_NeoPixel stripA = Adafruit_NeoPixel(28, PINB, NEO_GRB + NEO_KHZ800); //Shows Shoot Cycle (rollers, hold ball, shoot ready, shooting)
Adafruit_NeoPixel stripC = Adafruit_NeoPixel(24, PINC, NEO_GRB + NEO_KHZ800); //Shows IR fieldpos and line detected

#include "utilities.h"
#include "packets.h"
#include "animations.h"

Animation* animationDrive;
Animation* animationA;
Animation* animationC;

bool firstRun;

//The setup of most of the code
void setup()
{
	animationA = new Scanner(stripA.Color(255,0,0),0,stripA);
	animationC = new FadePulse(stripC.Color(255,0,0),0,stripC);
	animationDrive = new FadePulse(driveStrip.Color(255,0,0),0,driveStrip);
	
	pinMode(13,OUTPUT);
	pinMode(PINA,OUTPUT);
	pinMode(PINC,OUTPUT);
	pinMode(PIND,OUTPUT);
	
	Wire.onReceive(getPackets);
	Wire.begin(2);
  
  Serial.begin(9600);
	
	stripA.begin();
	stripA.show();
	stripC.begin();
	stripC.show();
	driveStrip.begin();
	driveStrip.show();
	
}
/*
void setAnimationA()
{
	delete animationA;
		
	if(gameState == MODE_TELEOP)
	{
		if(robotState == STATE_SHOOT_READY)
		{
			animationA = new Strobes(stripA.Color(0,0,255),stripA.Color(0,0,0), 031, 5, stripA);
		}
		else if(robotState == STATE_SHOOTING)
		{
			animationA = new Scanner(stripA.Color(0,255,0), 0, stripA);
		}
		else if(robotState == STATE_HOLD_BALL)
		{
			animationA = new Bounce(stripA.Color(0,0,255), 10, stripA);
		}
		else if(robotState == STATE_ROLLERS)
		{
			animationA = new Pixelate(stripA.Color(0,255,0),stripA.Color(0,0,255),0, stripA);
		}
		else
		{
			animationA = new FadePulse(stripA.Color(0, 255,0), 0, stripA);
		}
	}
}
void setAnimationB()
{
	delete animationB;
		
	if(gameState == MODE_TELEOP)
	{
		if(gear == HIGH_GEAR)
		{
			animationB = new Steady(stripB.Color(0,255,0), 0, stripB);
		}
		else
		{
			animationB = new Steady(stripB.Color(0,0,255), 0, stripB);
		}
	}
}
void setAnimationC()
{
	delete animationC;
	if(gameState == MODE_TELEOP)
	{
		if(lineFound)
		{
			animationC = new Strobes(stripC.Color(255,0,0),stripC.Color(0,0,0), 125, 10, stripC);
		}
		else
		{
			animationC = new FadePulse(stripC.Color(0, 255,0), 0, stripC);
		}
	}
}
void setAnimationDrive()
{
	delete animationDrive;
	if(gameState == MODE_TELEOP)
	{
		if(omni)
		{
			animationDrive = new Bounce(driveStrip.Color(0,255,0), 10, driveStrip);
		}
		else
		{
			animationDrive = new Stripes(driveStrip.Color(0,255,0), driveStrip.Color(255,255,255), 0, driveStrip);
		}
	}
}
*/
void setAllAnimations()
{
	delete animationA;
	delete animationC;
	delete animationDrive;
		
	if(gameState == MODE_AUTO)
	{
		if(alliance == RED_ALLIANCE)
		{
			animationA = new Scanner(stripA.Color(255,0,0),0, stripA);
			animationC = new FadePulse(stripC.Color(255,0,0),0, stripC);
			animationDrive = new FadePulse(driveStrip.Color(255,0,0),0, driveStrip);
		}
		else if(alliance == BLUE_ALLIANCE)
		{
			animationA = new Scanner(stripA.Color(0,0,255),0, stripA);
			animationC = new FadePulse(stripC.Color(0,0,255),0, stripC);
			animationDrive = new FadePulse(driveStrip.Color(0,0,255),0, driveStrip);
		}
		else
		{
			animationA = new Scanner(stripA.Color(255,255,255),0, stripA);
			animationC = new FadePulse(stripC.Color(255,255,255),0, stripC);
			animationDrive = new FadePulse(driveStrip.Color(255,255,255),0, driveStrip);
		}
	}
	/*
	else if(gameState == MODE_AUTO)
	{
		if(alliance == RED_ALLIANCE)
		{
			animationA = new Pixelate(stripA.Color(255,0,0),stripA.Color(0,255,0),0, stripA);
			animationB = new Pixelate(stripB.Color(255,0,0),stripB.Color(0,255,0),0, stripB);
			animationC = new Pixelate(stripC.Color(255,0,0),stripC.Color(0,255,0),0, stripC);
			animationDrive = new Pixelate(driveStrip.Color(255,0,0),driveStrip.Color(0,255,0),0, driveStrip);
			animationE = new Pixelate(stripE.Color(255,0,0),stripE.Color(0,255,0),0, stripE);
		}
		else if(alliance == BLUE_ALLIANCE)
		{
			animationA = new Pixelate(stripA.Color(0,0,255),stripA.Color(0,255,0),0, stripA);
			animationB = new Pixelate(stripB.Color(0,0,255),stripB.Color(0,255,0),0, stripB);
			animationC = new Pixelate(stripC.Color(0,0,255),stripC.Color(0,255,0),0, stripC);
			animationDrive = new Pixelate(driveStrip.Color(0,0,255),driveStrip.Color(0,255,0),0, driveStrip);
			animationE = new Pixelate(stripE.Color(0,0,255),stripE.Color(0,255,0),0, stripE);
		}
		else
		{
			animationA = new Pixelate(stripA.Color(255,255,255),stripA.Color(0,255,0),0, stripA);
			animationB = new Pixelate(stripB.Color(255,255,255),stripB.Color(0,255,0),0, stripB);
			animationC = new Pixelate(stripC.Color(255,255,255),stripC.Color(0,255,0),0, stripC);
			animationDrive = new Pixelate(driveStrip.Color(255,255,255),driveStrip.Color(0,255,0),0, driveStrip);
			animationE = new Pixelate(stripE.Color(255,255,255),stripE.Color(0,255,0),0, stripE);
		}
	}
	*/
	else if(gameState == MODE_TELEOP)
	{
		bool a,b,c;
		if(gear == HIGH_GEAR)
		{
		a=true;
		}
		else
		{
		a=false;
		}
		
		if(robotState == STATE_SHOOT_READY)
		{
		b=true;
		}
		else
		{
		b=false;
		}
		
		if(omni != 0)
		{
		c=true;
		}
		else
		{
		c=false;
		}
		
		animationA = new FieldPOS(a,b,c,0, stripA);
		animationC = new FieldPOS(a,b,c,0, stripC);
		animationDrive = new FieldPOS(a,b,c,0, driveStrip);
	}
	else if(gameState == MODE_DISABLED)
	{
		//animationA = new PinkSwag(stripA.Color(0,255,0),0, stripA);
		//animationC = new PinkSwag(stripC.Color(0,255,0),0, stripC);
		//animationDrive = new PinkSwag(driveStrip.Color(0,255,0),0, driveStrip);
		animationA = new Pixelate(stripA.Color(0,255,0),stripA.Color(0,0,0),0, stripA);
		animationC = new Pixelate(stripC.Color(0,255,0),stripC.Color(0,0,0),0, stripC);
		animationDrive = new Pixelate(driveStrip.Color(0,255,0),driveStrip.Color(0,0,0),0, driveStrip);
		//255,0,120
	}
	else
	{
		animationA = new FadePulse(stripA.Color(255,0,0),0, stripA);
		animationC = new FadePulse(stripC.Color(255,0,0),0, stripC);
		animationDrive = new FadePulse(driveStrip.Color(255,0,0),0, driveStrip);
		
		//animation = new Pixelate(strip.Color(0,255,0),strip.Color(255,255,255),0);
		//animation = new PixThree(strip.Color(255,0,0),strip.Color(255,255,255),strip.Color(0,0,255),0);
	}
}

void loop()
{
	//delay(animationA->sleepTime);
	bool completed = animationA->update();
	//delay(animationC->sleepTime);
	bool completedC = animationC->update();
	//delay(animationDrive->sleepTime);
	bool completedD = animationDrive->update();

	delay(20);
/*
  Serial.print(" 1.");
  Serial.print(gameState);
  Serial.print(" 2.");
  Serial.print(alliance);
  Serial.print(" 3.");
  Serial.print(gear);
  Serial.print(" 4.");
  Serial.print(omni);
  Serial.print(" 5.");
  Serial.print(robotState);
  Serial.print(" 6.");
  Serial.println(pressure); */
	if(firstRun)
	{	
		if(newData)
		{
			setAllAnimations();
			newData = false;
			firstRun = false;
		}
	}
	else
	{
		if(newData || completed || completedC || completedD)
		{
			setAllAnimations();
			newData = false;
		}
	}
	/*
	if(newDataA || completed)
	{
		setAnimationA();
		newDataA = false;
	}
	if(newDataB || completedB)
	{
		setAnimationB();
		newDataB = false;
	}
	if(newDataC || completedC)
	{
		setAnimationC();
		newDataC = false;
	}
	if(newDataDrive || completedD)
	{
		setAnimationDrive();
		newDataDrive = false;
	}
	*/
	
}
