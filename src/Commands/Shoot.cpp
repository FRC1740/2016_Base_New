#include "Shoot.h"

Shoot::Shoot()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(shooter);
}

// Called just before this Command runs the first time
void Shoot::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void Shoot::Execute()
{
	double motorRPM = shooter->getRPM();
	char motorRPMString[64] = "";

	shooter->shoot();
	sprintf(motorRPMString, "%f", motorRPM);
	printf(motorRPMString);

	SmartDashboard::PutNumber("Shooter Speed: ", motorRPM);
}

// Make this return true when this Command no longer needs to run execute()
bool Shoot::IsFinished() {
	if (oi->shoot->Get())
		return false;
	else
		return true;
}

// Called once after isFinished returns true
void Shoot::End() {

	shooter->shootStop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Shoot::Interrupted() {

	shooter->shootStop();
}
