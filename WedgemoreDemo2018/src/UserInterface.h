//UserInterface.h
//Created on: 2/25/2018
//Author: Colin Bradley
#ifndef SRC_USERINTERFACE_H_
#define SRC_USERINTERFACE_H_
#include "WPILib.h"
struct WedgemoreUserInput{
	float LeftSpeed = 0.0, RightSpeed = 0.0;
	bool Shoot = false;
	bool Charge = false;
	bool ShooterDown = false;
	bool ShooterUp = false;
	bool eStop1 = false, eStop2 = false;
	float RightTrigger = 0, LeftTrigger = 0;
};
class UserInterface{
private:
	Joystick m_controller;
public:
	UserInterface();
	virtual ~UserInterface();
	void GetControllerValues(WedgemoreUserInput *wui);
};
#endif /* SRC_USERINTERFACE_H_ */
