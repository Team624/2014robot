#include "packets.h"
#include "IRILights.h"

volatile uint8_t gameState = MODE_UNKNOWN;
volatile uint8_t robotState = STATE_UNKNOWN;
volatile uint8_t alliance = UNKNOWN_ALLIANCE;
volatile uint8_t gear = LOW_GEAR;
volatile uint8_t omni = 0;
volatile uint8_t pressure = PRESSURE_EMPTY;
volatile uint32_t shootStartTime = 0;

void readPacket(int numBytes)
{
	Wire.read(); //register

	gameState = Wire.read(); //1
	
	alliance = Wire.read(); //2
	
	gear = Wire.read(); //3
	
	omni = Wire.read(); //4
  
	uint8_t oldRobotState = robotState;
	robotState = Wire.read(); //5
  if(robotState == STATE_SHOOTING && oldRobotState != STATE_SHOOTING) {
    shootStartTime = counter;
  }
	pressure = Wire.read(); //6
	
}