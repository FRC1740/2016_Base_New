#include "BoilerRangeLight.h"

BoilerRangeLight::BoilerRangeLight()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(shooter);
}

// Called just before this Command runs the first time
void BoilerRangeLight::Initialize()
{
	datalogger->Log("RangeLight::Initialize()", STATUS_MESSAGE);
	shooter->Light(1);
}

// Called repeatedly when this Command is scheduled to run
void BoilerRangeLight::Execute()
{
	char rangeString[14];
	float rangeInches;

	rangeInches = shooter->GetRangeInches();
	sprintf(rangeString, "%5.2f inches", rangeInches);

	// Guessing on this range...
	if (rangeInches >= MIN_RANGE && rangeInches <= MAX_RANGE)
	{
		shooter->Light(1);
	}
	else {
		shooter->Light(0);
	}

	SmartDashboard::PutString("Range to Boiler: ", rangeString);
}

// Make this return true when this Command no longer needs to run execute()
bool BoilerRangeLight::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void BoilerRangeLight::End()
{
	shooter->Light(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BoilerRangeLight::Interrupted()
{
	shooter->Light(0);
}
