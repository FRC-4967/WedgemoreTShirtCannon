/*
 * Shooter.h
 *
 *  Created on: Jan 31, 2016
 *      Author: Joey172
 */

#ifndef SRC_SHOOTER_H_
#define SRC_SHOOTER_H_
#include <wpilib.h>
#include "TrapezoidalMove.h"
#define SHOOTER_SCALE (1.0/360.0)
class Shooter
{
private:
	CANTalon m_lift, m_shoot1, m_shoot2;
	Solenoid m_kicker;
	DigitalOutput m_aimLight, m_runNgunLight;
	float max_speed = 0.5;
	float m_startTime = 0;
	float m_liftAccel = 0, m_liftMaxSpeed = 0;
	Timer m_liftTimer, m_spinUpTimer, m_spinShootTimer;
	float m_currentPosition = 0;
	float m_targetPosition = 0;
	unsigned m_liftZero = 0;
	TrapezoidalMove m_liftMove;
public:
	Shooter();
	virtual ~Shooter();

	//void RotateTo(float position);
	//void Rotate(float increment);
	void Lift(float incrAngle);
	void LiftTo(float angle);
	void Shoot(bool val);
	void Spinup(float speed);
	void SpinShoot();
	void Pickup();
	void Stop();
	void ToggleLight();
	void ToggleRunLight();
	/**
	 * Call every loop to update async actions.
	 */
	void Update();
	void Zero();
	double GetLiftPosition();
	double GetLiftAngle();
	int shooter_zero = 0;
};

#endif /* SRC_SHOOTER_H_ */
