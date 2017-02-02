#include "RangeFinder.h"
#include "../RobotMap.h"
#include "../Commands/RangeLight.h" // YOU MUST INCLUDE IT to set it as the default command

RangeFinder::RangeFinder() : Subsystem("RangeFinder")
{
	rangeBoiler = new Ultrasonic(BOILER_RANGE_OUTPUT_PORT, BOILER_RANGE_INPUT_PORT);
	rangeBoiler->SetAutomaticMode(true);
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
		light->Set(Relay::kForward);
	}
	else
	{
		light->Set(Relay::kOff);
	}
}
