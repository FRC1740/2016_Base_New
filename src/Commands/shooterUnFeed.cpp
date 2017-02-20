#include "shooterUnFeed.h"

shooterUnFeed::shooterUnFeed()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(shooter);
}

// Called just before this Command runs the first time
void shooterUnFeed::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void shooterUnFeed::Execute()
{
	shooter->FeederReverse();
}

// Make this return true when this Command no longer needs to run execute()
bool shooterUnFeed::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void shooterUnFeed::End()
{
	shooter->FeederStop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void shooterUnFeed::Interrupted()
{
	shooter->FeederStop();
}
