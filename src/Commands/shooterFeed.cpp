#include "shooterFeed.h"

shooterFeed::shooterFeed()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(shooter);
}

// Called just before this Command runs the first time
void shooterFeed::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void shooterFeed::Execute()
{
	shooter->FeederStart();
}

// Make this return true when this Command no longer needs to run execute()
bool shooterFeed::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void shooterFeed::End()
{
	shooter->FeederStop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void shooterFeed::Interrupted()
{
	shooter->FeederStop();
}
