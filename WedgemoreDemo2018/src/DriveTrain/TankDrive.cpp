//TankDrive.cpp
//Created on: 2/25/2018
//Author: Colin Bradley
#include <DriveTrain/TankDrive.h>
#include "RobotMap.h"
using namespace std;
TankDrive::TankDrive() :
		m_leftMotor1(LEFTDRIVE1),
		m_leftMotor2(LEFTDRIVE2),
		m_rightMotor1(RIGHTDRIVE1),
		m_rightMotor2(RIGHTDRIVE2)
{
	m_rightMotor1.SetInverted(true);
	m_leftMotor2.Follow(m_leftMotor1);
	m_rightMotor2.Follow(m_rightMotor1);
}
TankDrive::~TankDrive(){}
void TankDrive::Drive(float leftSpeed, float rightSpeed){
	if(fabs(leftSpeed) < 0.1) leftSpeed = 0;
	if(fabs(rightSpeed) < 0.1) rightSpeed = 0;
	leftSpeed*=.3;
	rightSpeed*=.3;
	m_leftMotor1.Set(ControlMode::PercentOutput,leftSpeed);
	m_rightMotor1.Set(ControlMode::PercentOutput,rightSpeed);
}
