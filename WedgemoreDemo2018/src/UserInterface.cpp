//UserInterface.cpp
//Created on: 2/25/2018
//Author: Colin Bradley
#include <UserInterface.h>
#include <WPILib.h>
#include "RobotMap.h"
//The Robot's name is "Wedgemore"
UserInterface::UserInterface():m_controller(0){}
UserInterface::~UserInterface(){}
void UserInterface::GetControllerValues(WedgemoreUserInput *wui){
	wui->LeftSpeed = m_controller.GetRawAxis(LEFT_JOYSTICK);
	wui->RightSpeed = m_controller.GetRawAxis(RIGHT_JOYSTICK);
	wui->RightTrigger = m_controller.GetRawAxis(SHOOT);
	wui->Charge = m_controller.GetRawButton(CHARGE);
	wui->ShooterUp = m_controller.GetRawButton(SHOOTER_UP);
	wui->LeftTrigger = m_controller.GetRawAxis(SHOOTER_DOWN);
	if (wui->LeftTrigger>=0.5){wui->ShooterDown = true;}
	else {wui->ShooterDown = false;}
	if (wui->RightTrigger>=0.5){wui->Shoot = true;}
	else {wui->Shoot = false;}
	wui->eStop1 = m_controller.GetRawButton(ESTOP1);
	wui->eStop2 = m_controller.GetRawButton(ESTOP2);
}
