//TankDrive.h
//Created on: 2/25/2018
//Author: Colin Bradley
#ifndef SRC_TANKDRIVE_H_
#define SRC_TANKDRIVE_H_
#include <WPILib.h>
#include <ctre/phoenix.h>
class TankDrive{
private:
	TalonSRX m_leftMotor1, m_leftMotor2, m_rightMotor1, m_rightMotor2;
public:
	TankDrive();
	virtual ~TankDrive();
	void Drive(float leftSpeed, float rightSpeed);
};
#endif /* SRC_TANKDRIVE_H_ */
