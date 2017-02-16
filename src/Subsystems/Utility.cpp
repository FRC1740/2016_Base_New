#include "Utility.h"
#include "../RobotMap.h"

Utility::Utility(): Subsystem("Utility")
{
	// utility_motor = new TalonSRX(UTILITY_MOTOR_PORT);
	gearLight = new Relay(GEAR_LIGHT_RELAY_PORT);
}

void Utility::gearLightOn()
{
	gearLight->Set(Relay::kForward);
}

void Utility::gearLightOff()
{
	gearLight->Set(Relay::kOff);
}
/* */
