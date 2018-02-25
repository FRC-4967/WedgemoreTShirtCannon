//RobotMap.h
//Created on: 2/25/2018
//Author: Colin Bradley
#ifndef SRC_ROBOTMAP_H_
#define SRC_ROBOTMAP_H_
enum GameController {
	SHOOT =3,
	CHARGE = 6,
	SHOOTER_UP =5,
	SHOOTER_DOWN=2,
	RIGHT_JOYSTICK=5,
	LEFT_JOYSTICK=1,
	ESTOP1=7,
	ESTOP2=8
};
enum SolenoidMap {
	SHOOTERSOL = 7,
	CHARGEYUPPY = 6,
};
enum CANTalonMap {
	RIGHTDRIVE1,
	RIGHTDRIVE2,
	LEFTDRIVE1,
	LEFTDRIVE2,
	LIFT,
};
#endif /* SRC_ROBOTMAP_H_ */
