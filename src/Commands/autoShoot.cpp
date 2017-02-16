#include "autoShoot.h"

autoShoot::autoShoot(double time)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(shooter);
	SetTimeout(time);
}

// Called just before this Command runs the first time
void autoShoot::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void autoShoot::Execute()
{
	shooter->shoot();
}

// Make this return true when this Command no longer needs to run execute()
bool autoShoot::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void autoShoot::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void autoShoot::Interrupted() {

}
