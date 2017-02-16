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
	double motorRPM = shooter->GetRPM();
	char motorRPMString[64] = "";

	shooter->Shoot();
	sprintf(motorRPMString, "%f", motorRPM);
	printf(motorRPMString);

	SmartDashboard::PutNumber("Shooter Speed: ", motorRPM);
}

// Make this return true when this Command no longer needs to run execute()
bool Shoot::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Shoot::End() {

	shooter->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Shoot::Interrupted() {

	shooter->Stop();
}
