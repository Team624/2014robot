/*
CRIO to Arduino Byte Naming List
0 - Game State (teleop, auton, unknown)
1 - Alliance Color (red, blue, unknown)
2 - Gear (1st or 2nd)
3 - Throttle
4 - Robot State
5 - Omni Mode
6 - IR Line Detection Magic
*/

#define RED_ALIANCE 0
#define BLUE_ALIANCE 1
#define UNKNOWN_ALIANCE 2

#define MODE_UNKNOWN 0
#define MODE_DISABLED 1
#define MODE_AUTO 2
#define MODE_TELEOP 3

#define STATE_UNKNOWN 5
#define STATE_SHOOT_READY 0
#define STATE_SHOOTING 1
#define STATE_HOLD_BALL 2
#define STATE_ROLLERS 3
#define STATE_PASSING 4

#define LOW_GEAR 0
#define HIGH_GEAR 1


volatile uint8_t gameState = MODE_UNKNOWN;
volatile uint8_t robotState = STATE_UNKNOWN;
volatile uint8_t alliance = UNKNOWN_ALLIANCE;
volatile uint8_t fieldPos = 0;
volatile uint8_t lineFound = 0;
volatile uint8_t gear = HIGH_GEAR;
volatile uint8_t throttle = 0;
volatile uint8_t omni = 0;
volatile bool newData = false;

void getPackets(int numBytes)
{
//1 = Game State
//2 = Alliance
//3 = Gear
//4 = Throttle
//5 = Robot State
//6 = Omni
//7 = Field Positioning
	Wire.read();
	
	uint8_t oldGameState = gameState;
	gameState = Wire.read();
	if(gameState != oldGameState)
	{
		newData=true;
	}
	
	alliance = Wire.read();
	
	uint8_t oldGear = gear;
	gear = Wire.read();
	if(gear != oldGear)
	{
		newData=true;
	}
	
	throttle = Wire.read();
	
	uint8_t oldRobotState = robotState;
	robotState = Wire.read();
	if(robotState != oldRobotState)
	{
		newData=true;
	}
	
	omni = Wire.read();
	lineFound = Wire.read();
	//fieldPos = Wire.read();
}