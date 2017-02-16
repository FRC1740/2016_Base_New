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
	char rangeString[14];
	float rangeInches;

	rangeInches = rangefinder->GetRangeInches();
	sprintf(rangeString, "%5.2f inches", rangeInches);

	// Guessing on this range...
	if (rangeInches >= MIN_RANGE && rangeInches <= MAX_RANGE)
	{
		rangefinder->Light(1);
	}
	else {
		rangefinder->Light(0);
	}

	SmartDashboard::PutString("Range to Boiler: ", rangeString);

}

bool RangeLight::IsFinished()
{
	return false;
}

void RangeLight::End()
{
	rangefinder->Light(0);
	return;
}

void RangeLight::Interrupted()
{
	rangefinder->Light(0);
	return;
}
