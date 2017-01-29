#include "AimUp.h"

AimUp::AimUp() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(shooter);
}

// Called just before this Command runs the first time
void AimUp::Initialize() {

	shooter->aimUp();
}

// Called repeatedly when this Command is scheduled to run
void AimUp::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool AimUp::IsFinished() {

	if (oi->aimUp->Get())
		return false;
	else
		return true;
}

// Called once after isFinished returns true
void AimUp::End() {

	shooter->aimStop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AimUp::Interrupted() {

	shooter->aimStop();
}
