#include "WPILib.h"

#include "AnesthesiologistDrive.h"
#include "AnesthesiologistManipulator.h"
#include "AnesthesiologistPIDOutput.h"
#include "AnesthesiologistKicker.h"
#include "AnesthesiologistOperatorInterface.h"
#include "AnesthesiologistMacros.h"

class Anesthesiologist: public IterativeRobot
{
	AnesthesiologistDrive *drive;
	AnesthesiologistManipulator *manipulator;
	AnesthesiologistOperatorInterface *oi;
	Compressor *comp599;

public:	
	Anesthesiologist()
	{
		manipulator = new AnesthesiologistManipulator();
		drive = new AnesthesiologistDrive();
		oi = new AnesthesiologistOperatorInterface();
		comp599 = new Compressor(1, 1, 1, 1); 
		
		oi->dashboard->init();
		comp599->Start();
	}
	
	void RobotInit()
	{
	
	}
	
	void DisabledInit()
	{
	
	}
	
	void AutonomousInit()
	{
	
	}
	
	void TeleopInit()
	{
		drive->setLinVelocity(0);
		drive->setTurnSpeed(0, false);
		drive->drive();
	}
	
	void TestInit()
	{
	
	}
	
	void DisabledPeriodic()
	{
		smartDashboardPrint();
	}
	
	void AutonomousPeriodic()
	{
	
	
	}
	
	void TeleopPeriodic()
	{
		comp599->Start();
		
		while(IsOperatorControl())
		{
			 teleDrive();
			 smartDashboardPrint();
		}
	}
	
	void TestPeriodic()
	{
	
	}
	
	void teleDrive()
	{
		drive->setLinVelocity(-oi->getDriveJoystick()->GetY(Joystick::kRightHand));
		drive->setTurnSpeed(oi->getDriveJoystick()->GetX(Joystick::kRightHand), oi->getDriveJoystickButton(1));
		drive->drive();
		drive->shift(oi->getDriveJoystickButton(8), oi->getDriveJoystickButton(9));
		if(oi->getDriveJoystickButton(6))
		{
			comp599->Start();
		}
		else if(oi->getDriveJoystickButton(7))
		{
			comp599->Stop();
		}
	}
	
	void smartDashboardPrint()
	{
		//oi->dashboard->PutNumber("Linear Velocity: ", drive->getLinVelocity());
		//oi->dashboard->PutNumber("Turn Speed: ", drive->getTurnSpeed());
	}
};	

START_ROBOT_CLASS(Anesthesiologist);
