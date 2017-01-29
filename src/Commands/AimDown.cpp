#include "AimDown.h"

AimDown::AimDown() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(shooter);
}

// Called just before this Command runs the first time
void AimDown::Initialize() {

	shooter->aimDn();
}

// Called repeatedly when this Command is scheduled to run
void AimDown::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool AimDown::IsFinished() {

	if (oi->aimDn->Get())
		return false;
	else
		return true;
}

// Called once after isFinished returns true
void AimDown::End() {

	shooter->aimStop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AimDown::Interrupted() {

	shooter->aimStop();
}
