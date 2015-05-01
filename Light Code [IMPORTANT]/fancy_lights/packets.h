/*
CRIO to Arduino Byte Naming List
0 - Game State (teleop, auton, unknown)
1 - Alliance Color (red, blue, unknown)
2 - Gear (1st or 2nd)
3 - Throttle
4 - Robot State
5 - Omni Mode
6 - IR Line Detection Magic
7 - Line Detected?
*/
#define PRESSURE_EMPTY 0
#define PRESSURE_LOW 1
#define PRESSURE_FULL 2

#define RED_ALLIANCE 0
#define BLUE_ALLIANCE 1
#define UNKNOWN_ALLIANCE 2

#define MODE_UNKNOWN 0
#define MODE_DISABLED 1
#define MODE_AUTO 2
#define MODE_TELEOP 3

#define STATE_UNKNOWN 4
#define STATE_SHOOT_READY 0
#define STATE_SHOOTING 1
#define STATE_HOLD_BALL 2
#define STATE_ROLLERS 3


#define LOW_GEAR 1
#define HIGH_GEAR 0


volatile uint8_t gameState = MODE_UNKNOWN;
volatile uint8_t robotState = STATE_UNKNOWN;
volatile uint8_t alliance = UNKNOWN_ALLIANCE;
//volatile uint8_t fieldPos = 0;
volatile uint8_t gear = LOW_GEAR;
volatile uint8_t omni = 0;
volatile bool newData = false;
volatile uint8_t pressure = PRESSURE_EMPTY;
/*volatile bool newDataA = false;
volatile bool newDataB = false;
volatile bool newDataC = false;
volatile bool newDataDrive = false;
*/
void getPackets(int numBytes)
{
//1 = Game State
//2 = Alliance
//3 = Gear
//4 = Throttle
//5 = Robot State
//6 = Omni
//7 = Field Positioning
//8 = Line Detected?
//Serial.println("packet");
	//uint8_t oldLF=lineFound;
	/*Wire.read();
	if(oldLF!=lineFound)
	{
		newDataC=true;
	}
	*/
	Wire.read(); //register
	
	uint8_t oldGameState = gameState;
	gameState = Wire.read(); //1
	
	if(gameState != oldGameState)
	{
		newData=true;
	}
	
	alliance = Wire.read(); //2
	
	
	uint8_t oldGear = gear;
	gear = Wire.read(); //3
	if(gear != oldGear)
	{
		newData=true;
	}
	
	uint8_t oldOmni = omni;
	omni = Wire.read(); //4
	if(omni != oldOmni)
	{
		newData=true;
	}
	
	uint8_t oldRobotState = robotState;
	robotState = Wire.read(); //5
	
	if(robotState != oldRobotState)
	{
		newData=true;
	}
	
	uint8_t oldPressure = pressure;
	pressure = Wire.read(); //6
	
	if(pressure != oldPressure)
	{
		newData=true;
	}
	
	//throttle = Wire.read();
	//fieldPos = Wire.read();
	//lineFound = Wire.read();
	
	
}