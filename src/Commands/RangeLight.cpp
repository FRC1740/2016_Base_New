#include "RangeLight.h"
#include "../RobotMap.h"

RangeLight::RangeLight()
{
	Requires(rangefinder);
}

void RangeLight::Initialize()
{
	datalogger->Log("RangeLight::Initialize()", STATUS_MESSAGE);
	rangefinder->Light(1);
}

void RangeLight::Execute()
{

	/*
	if (rangefinder->rangeBoiler->GetRangeInches() > 36
			&& rangefinder->rangeBoiler->GetRangeInches() < 48) {

		rangefinder->Light(1);
	}
	else {
		rangefinder->Light(0);
	}
	SmartDashboard::PutNumber("Range to Boiler:", rangefinder->rangeBoiler->GetRangeInches());
//	SmartDashboard::PutNumber("Bottom Range:", rangefinder->rangeClimber->GetRangeInches());

 */
}

bool RangeLight::IsFinished()
{
	if (oi->climb->Get() == true)
		return false;
	else
		return true;
}

void RangeLight::End()
{
	rangefinder->Light(0);
	return;
}

void RangeLight::Interrupted()
{
	return;
}
