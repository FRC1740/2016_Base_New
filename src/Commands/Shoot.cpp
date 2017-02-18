#include "Shoot.h"

Shoot::Shoot()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(shooter);
	Requires(utility);
}

// Called just before this Command runs the first time
void Shoot::Initialize()
{
	SetTimeout(4.5);
}

// Called repeatedly when this Command is scheduled to run
void Shoot::Execute()
{
	char motorRPMString[64] = "";
	double motorRPM = shooter->GetRPM();
	// Are we going at optimum speed?
	if (motorRPM >= OPTIMUM_SHOOTER_RPM)
	{
		// Yes, use standard power
		shooter->Shoot(1.0);
	}
	else
	{
		// If not, bump up the power as much as necessary (or possible)
		shooter->Shoot(OPTIMUM_SHOOTER_RPM/motorRPM);
	}
	if (IsTimedOut())
	{
		utility->gearLightOn(); // FIXME: Remove/Just for testing
		shooter->FeederStart(); // FIXME: Add this for real robot
	}
	sprintf(motorRPMString, "%6.2f RPM", motorRPM);
	printf(motorRPMString);
	SmartDashboard::PutString("Shooter Speed: ", motorRPMString);
}

// Make this return true when this Command no longer needs to run execute()
bool Shoot::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Shoot::End() {

	shooter->Stop();
	utility->gearLightOff(); // FIXME: Remove/Just for testing
	shooter->FeederStop(); // FIXME: Add this for real robot
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Shoot::Interrupted() {

	shooter->Stop();
	utility->gearLightOff(); // FIXME: Remove/Just for testing
	shooter->FeederStop(); // FIXME: Add this for real robot
}
