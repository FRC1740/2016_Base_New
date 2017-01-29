#include "Shooter.h"
#include "../RobotMap.h"

#define AIM_POWER 1.0
#define SHOOT_POWER 0.5

Shooter::Shooter() : Subsystem("ExampleSubsystem") {

	shootMotor = new CANTalon(SHOOTER_MOTOR_ID);
	aimMotor = new CANTalon(AIM_MOTOR_ID);
}

void Shooter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Shooter::shoot()
{
	shootMotor->Set(-SHOOT_POWER);
}
void Shooter::aimUp()
{
	aimMotor->Set(-AIM_POWER);
}

void Shooter::aimDn()
{
	aimMotor->Set(AIM_POWER);
}
void Shooter::aimStop()
{
	aimMotor->Set(0.0);
}
void Shooter::shootStop()
{
	shootMotor->Set(0.0);
}
void Shooter::aim(float speed)
{
	aimMotor->Set(speed);
}
