#include "RangeFinder.h"
#include "../RobotMap.h"
#include "../Commands/RangeLight.h" // YOU MUST INCLUDE IT to set it as the default command

RangeFinder::RangeFinder() : Subsystem("RangeFinder")
{
	rangefinder_gear = new Ultrasonic(GEAR_SONAR_PORT_A, GEAR_SONAR_PORT_B);
	rangefinder_gear->SetAutomaticMode(true);
//	rangefinder_bottom = new Ultrasonic(6,7);
//	rangefinder_bottom->SetAutomaticMode(true);
	light = new Relay(LIGHT_BAR_RELAY_PORT);
}

void RangeFinder::InitDefaultCommand()
{
	SetDefaultCommand(new RangeLight());
}

void RangeFinder::Light(unsigned int state)
{
	if (state)
	{
//		light->Set(Relay::kForward);
	}
	else
	{
//		light->Set(Relay::kOff);
	}
}
