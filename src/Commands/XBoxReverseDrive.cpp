#include "XBoxReverseDrive.h"

XBoxReverseDrive::XBoxReverseDrive()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrain);
}

// Called just before this Command runs the first time
void XBoxReverseDrive::Initialize()
{
	drivetrain->ReverseDirection();
}

// Called repeatedly when this Command is scheduled to run
void XBoxReverseDrive::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool XBoxReverseDrive::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void XBoxReverseDrive::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void XBoxReverseDrive::Interrupted()
{

}
