#include "autoShoot.h"

autoShoot::autoShoot(double time)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(shooter);
	secondTimeout = time;
}

// Called just before this Command runs the first time
void autoShoot::Initialize()
{
	SetTimeout(4.5); // Allow time for shooter to spin up
}

// Called repeatedly when this Command is scheduled to run
void autoShoot::Execute()
{
	shooter->Shoot(.6);
	if (IsTimedOut())
	{
		shooter->FeederStart();
		SetTimeout(secondTimeout);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool autoShoot::IsFinished()
{
	return IsTimedOut();
	// return false;
}

// Called once after isFinished returns true
void autoShoot::End()
{
	shooter->Stop();
	shooter->FeederStop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void autoShoot::Interrupted()
{
	shooter->Stop();
	shooter->FeederStop();
}
