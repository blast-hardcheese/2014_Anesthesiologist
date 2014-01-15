#ifndef ANESTHESIOLOGIST_MANIPULATOR_H
#define ANESTHESIOLOGIST_MANIPULATOR_H
#include "WPILib.h"
#include "RobodoxTimer.h"
#include "AnesthesiologistMacros.h"

class AnesthesiologistManipulator
{
public:
	AnesthesiologistManipulator();
	AnesthesiologistManipulator(UINT8 intakeRollerVictorChannel, 
								UINT8 intakeArmVictorChannel);
	~AnesthesiologistManipulator();
	
	void intakeBall(bool intake);
	
	void setRoller();	
	void setVelocity(double input);
	double getVelocity();
	
	void moveArmEncoder(double target, double speed);
	void setArm(double velocity);
	double getEncoder();
	
	bool isAtTarget;
	
	double initTicks;
	double currentTicks; 
	double deltaTicks;
	double offset;
	
	RobodoxTimer *timer;
	Encoder *armEncoder;
	
private:
	Victor *intakeRoller;
	DigitalInput *intakeSwitch;
	Victor *intakeArm;
	double targetVelocity;
	
};
#endif