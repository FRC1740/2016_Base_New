#include "CameraTurn.h"

CameraTurn::CameraTurn(float a)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(camera);
	Angle = a;
}

// Called just before this Command runs the first time
void CameraTurn::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void CameraTurn::Execute()
{
	if (Angle < 0)
		camera->TurnLeft();
	else if (Angle > 0)
		camera->TurnRight();
}

// Make this return true when this Command no longer needs to run execute()
bool CameraTurn::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void CameraTurn::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CameraTurn::Interrupted()
{

}
