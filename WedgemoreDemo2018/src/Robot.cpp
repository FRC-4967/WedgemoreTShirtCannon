#include <WPILib.h>
#include "UserInterface.h"
#include "DriveTrain/TankDrive.h"
#include "Shooter.h"
class Wedgemore: public IterativeRobot
{
private:
	TankDrive m_tank;
	Shooter m_shooter;
	UserInterface ui;
	WedgemoreUserInput wui;
	bool myDisableFlag = false;
public:
	Wedgemore(){}
	void RobotInit(){}
	void AutonomousInit(){}
	void AutonomousPeriodic(){}
	void TeleopInit(){}
	void TeleopPeriodic(){
		ui.GetControllerValues(&wui);

		float liftSpeed;
		if (wui.ShooterUp)liftSpeed=0.005;
		else if (wui.ShooterDown)liftSpeed=-0.005;
		else liftSpeed = 0;

		m_shooter.Charge(wui.Charge);
		m_shooter.Shoot(wui.Shoot);

		float leftSpeed = wui.RightSpeed;
		float rightSpeed = wui.LeftSpeed;

		printf("Lift: %f, Right: %f, Left: %f\n", liftSpeed,rightSpeed,leftSpeed);
		m_shooter.Periodic(liftSpeed);
		m_tank.Drive(leftSpeed, rightSpeed);

		if (wui.eStop1 || wui.eStop2){
			myDisableFlag = true;
			}
	}
	void TestPeriodic(){}
	void DisabledInit(){
		m_shooter.Shoot(false);
		m_shooter.Charge(false);
	}
};

START_ROBOT_CLASS(Wedgemore)
