#include "Shooter.h"
#include "../RobotMap.h"

#define SHOOT_POWER 0.6

Shooter::Shooter() : Subsystem("ExampleSubsystem") {

	shootMotor = new CANTalon(SHOOTER_MOTOR_ID);
	shootMotor->SetSafetyEnabled(false);
	// shootMotor->SetExpiration(.1);

	gateMotor = new CANTalon(GATE_MOTOR_ID);
	gateMotor->SetSafetyEnabled(false);
	// gateMotor->SetExpiration(.1);

	shooterCounter = new Counter(SHOOTER_COUNTER_DIO_PORT);
	shooterCounter->Reset();
}

void Shooter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Shooter::Shoot()
{
	shootMotor->Set(-SHOOT_POWER);
}
void Shooter::Stop()
{
	shootMotor->Set(0.0);
}
double Shooter::GetRPM()
{
	return shooterCounter->GetPeriod(); // return RPM
}
void Shooter::BreachOpen()
{
}
void Shooter::BreachClose()
{
}
