#include "RangeFinder.h"
#include "../RobotMap.h"
#include "../Commands/RangeLight.h" // YOU MUST INCLUDE IT to set it as the default command

RangeFinder::RangeFinder() : Subsystem("RangeFinder")
{
	// Digital sonar. Third argument 0=inches, 1=millimeters
	/* Today's Headlines: Digital rangefinder baffles Programming Mentor... Tune in for details at 11
	rangeBoiler = new Ultrasonic(BOILER_RANGE_OUTPUT_PORT, BOILER_RANGE_INPUT_PORT, frc::Ultrasonic::DistanceUnit::kInches);
	rangeBoiler->SetAutomaticMode(true);
	/* */
	rangeBoiler = new AnalogInput(ROBORIO_ANALOG_ZERO);
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

float RangeFinder::GetAverageVoltage()
{
	return rangeBoiler->GetAverageVoltage();
}

float RangeFinder::GetRangeInches()
{
	return rangeBoiler->GetAverageVoltage() * IN_FACTOR;
}
