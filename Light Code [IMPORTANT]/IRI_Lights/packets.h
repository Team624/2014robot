#ifndef PACKETS_H
#define PACKETS_H

#include <Wire.h>

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

#define STATE_SHOOT_READY 0
#define STATE_UNKNOWN 1
#define STATE_SHOOTING 2
#define STATE_SOFT_SHOOT 3
#define STATE_TOSS 4

#define OMNI_TRACTION 0
#define OMNI_OMNI 1
#define OMNI_SWAGROLL 2

#define LOW_GEAR 1
#define HIGH_GEAR 0

extern volatile uint8_t gameState;
extern volatile uint8_t robotState;
extern volatile uint8_t alliance;
extern volatile uint8_t gear;
extern volatile uint8_t omni;
extern volatile uint8_t pressure;
extern volatile unsigned long shootStartTime;

void readPacket(int numBytes);

#endif