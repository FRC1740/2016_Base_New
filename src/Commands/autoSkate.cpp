#include "autoSkate.h"

autoSkate::autoSkate(float dir, float s, float t) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrain);
	direction = dir;
	speed = s;
	SetTimeout(t);
}

// Called just before this Command runs the first time
void autoSkate::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void autoSkate::Execute() {

	if (direction == LEFT)
		drivetrain->SkateLeft(speed);
	else
		drivetrain->SkateRight(speed);
}

// Make this return true when this Command no longer needs to run execute()
bool autoSkate::IsFinished()
{
	return IsTimedOut();
}

// Called once after isFinished returns true
void autoSkate::End()
{
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void autoSkate::Interrupted() {

}
