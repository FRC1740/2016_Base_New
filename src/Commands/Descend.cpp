#include "Descend.h"

Descend::Descend() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(climber);
}

// Called just before this Command runs the first time
void Descend::Initialize() {

		climber->descend();
}

// Called repeatedly when this Command is scheduled to run
void Descend::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool Descend::IsFinished() {

	if (oi->descend->Get())
		return false;
	else
		return true;
}

// Called once after isFinished returns true
void Descend::End() {
	climber->stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Descend::Interrupted() {
	climber->stop();
}
