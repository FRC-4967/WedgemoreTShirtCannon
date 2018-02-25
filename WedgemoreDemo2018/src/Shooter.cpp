//Shooter.cpp
//Created on: 2/25/2018
//Author: Colin Bradley
#include "Shooter.h"
#include "RobotMap.h"
#include <iostream>
#include <WPILib.h>
using namespace std;
Shooter::Shooter() :m_lift(LIFT),m_shooter(SHOOTERSOL),m_charger(CHARGEYUPPY){
	m_lift.SetSensorPhase(true);
	m_liftPosition = 0;
}
Shooter::~Shooter(){}
void Shooter::Shoot(bool val){
	if (!m_shooting && val){
	m_shooter.Set(true);
	m_shootTimer.Reset();
	m_shootTimer.Start();
	m_shooting = true;
	}
}
void Shooter::Charge(bool charge) {
	m_charger.Set(charge);
}
void Shooter::Periodic(float lift) {
	static Timer timer;
	float shootTime = m_shootTimer.Get();
	if (shootTime >= 1) {
		m_shooter.Set(false);
		m_shootTimer.Stop();
		m_shooting = false;
	}
	m_liftPosition+=lift;
	m_lift.Set(ControlMode::Position,m_liftPosition);
}
