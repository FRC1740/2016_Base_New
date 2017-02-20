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
		shooter->Shoot(SHOOT_POWER);
		utility->gearLightOn(); // Double Duty used to indicate motor up to speed
	}
	else
	{
		// If not, bump up the power as much as necessary (or possible)
		shooter->Shoot(OPTIMUM_SHOOTER_RPM/motorRPM * SHOOT_POWER);
		utility->gearLightOff(); // Double Duty used to indicate motor up to speed
	}
	if (IsTimedOut())
	{
		utility->gearLightOn(); // Double Duty used to indicate motor up to speed
//		shooter->FeederStart(); // Isolated into it's own function & OI button
	}
	sprintf(motorRPMString, "%6.2f RPM", motorRPM);
	printf(motorRPMString);
	SmartDashboard::PutString("Shooter Speed: ", motorRPMString);
}

// Make this return true when this Command no longer needs to run execute()
bool Shoot::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Shoot::End()
{
	shooter->Stop();
	utility->gearLightOff(); // Double Duty used to indicate motor up to speed
//	shooter->FeederStop(); // Isolated into it's own function & OI button
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Shoot::Interrupted()
{
	shooter->Stop();
	utility->gearLightOff(); // Double Duty used to indicate motor up to speed
//	shooter->FeederStop();  // Isolated into it's own function & OI button
}
