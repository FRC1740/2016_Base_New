#include "shooterDoorOpen.h"

shooterDoorOpen::shooterDoorOpen()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(shooter);
}

// Called just before this Command runs the first time
void shooterDoorOpen::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void shooterDoorOpen::Execute()
{
	shooter->DoorOpen();
}

// Make this return true when this Command no longer needs to run execute()
bool shooterDoorOpen::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void shooterDoorOpen::End()
{
	shooter->DoorClose();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void shooterDoorOpen::Interrupted()
{
	shooter->DoorClose();
}
