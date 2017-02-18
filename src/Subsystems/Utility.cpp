#include "Utility.h"
#include "../RobotMap.h"

Utility::Utility(): Subsystem("Utility")
{
	// utility_motor = new TalonSRX(UTILITY_MOTOR_PORT);
	gearLight = new frc::Relay(GEAR_LIGHT_RELAY_PORT);
}

void Utility::gearLightOn()
{
	gearLight->Set(frc::Relay::kForward);
}

void Utility::gearLightOff()
{
	gearLight->Set(frc::Relay::kOff);
}
/* */
