//Shooter.h
//Created on: 2/25/2018
//Author: Colin Bradley
#ifndef SRC_SHOOTER_H_
#define SRC_SHOOTER_H_
#include <WPILib.h>
#include <ctre/Phoenix.h>
class Shooter{
private:
	TalonSRX m_lift;
	Solenoid m_shooter, m_charger;
	float m_liftPosition;
	Timer m_shootTimer;
	bool m_shooting = false;
public:
	Shooter();
	virtual ~Shooter();
	void Shoot(bool val);
	void Charge(bool charge);
	void Periodic(float lift);
};
#endif /* SRC_SHOOTER_H_ */
