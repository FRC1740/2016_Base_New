#include "GearLight.h"

GearLight::GearLight() {
	// Use Requires() here to declare subsystem dependencies
	Requires(utility);
}

// Called just before this Command runs the first time
void GearLight::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void GearLight::Execute()
{
	utility->gearLightOn();
}

// Make this return true when this Command no longer needs to run execute()
bool GearLight::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void GearLight::End()
{
	utility->gearLightOff();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GearLight::Interrupted()
{
	utility->gearLightOff();
}
