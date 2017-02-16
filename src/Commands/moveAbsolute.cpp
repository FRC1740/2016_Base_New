#include "moveAbsolute.h"

moveAbsolute::moveAbsolute(double s, double time) {
	// Use Requires() here to declare subsystem dependencies
	Requires(pidgyrodrive);
	speed = s;
	SetTimeout(time);
}

// Called just before this Command runs the first time
void moveAbsolute::Initialize()
{
	pidgyrodrive->autoMove(speed);
}

// Called repeatedly when this Command is scheduled to run
void moveAbsolute::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool moveAbsolute::IsFinished() {
	return IsTimedOut();

}

// Called once after isFinished returns true
void moveAbsolute::End()
{
	pidgyrodrive->stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void moveAbsolute::Interrupted()
{
	pidgyrodrive->stop();
}
