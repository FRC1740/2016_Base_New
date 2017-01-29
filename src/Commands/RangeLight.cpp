#include "RangeLight.h"
#include "../RobotMap.h"

RangeLight::RangeLight()
{
	Requires(rangefinder);
}

void RangeLight::Initialize()
{
	datalogger->Log("RangeLight::Initialize()", STATUS_MESSAGE);
}

void RangeLight::Execute()
{

	if (rangefinder->rangeBoiler->GetRangeInches() > 48
			&& rangefinder->rangeBoiler->GetRangeInches() < 72) {

		rangefinder->Light(1);
	}
	else {
		rangefinder->Light(0);
	}
	SmartDashboard::PutNumber("Range to Boiler:", rangefinder->rangeBoiler->GetRangeInches());
//	SmartDashboard::PutNumber("Bottom Range:", rangefinder->rangeClimber->GetRangeInches());
}

bool RangeLight::IsFinished()
{
	return false;
}

void RangeLight::End()
{
	return;
}

void RangeLight::Interrupted()
{
	return;
}
