#include "Shooter.h"
#include "../RobotMap.h"

#define SHOOT_POWER 0.6

Shooter::Shooter() : Subsystem("ExampleSubsystem") {

	shootMotor = new CANTalon(SHOOTER_MOTOR_ID);
	gateMotor = new CANTalon(AIM_MOTOR_ID);
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
void Shooter::shootStop()
{
	shootMotor->Set(0.0);
}
void Shooter::breachOpen()
{
}
void Shooter::breachClose()
{
}
