#include "Utility.h"
#include "../RobotMap.h"

Utility::Utility(): Subsystem("Utility")
{
	utility_motor = new TalonSRX(UTILITY_MOTOR_PORT);
}
