#include "Shooter.h"
#include "../Commands/BoilerRangeLight.h" // YOU MUST INCLUDE IT to set it as the default command

Shooter::Shooter() : Subsystem("Shooter") {

	shootMotor = new CANTalon(SHOOTER_MOTOR_ID);
	shootMotor->SetSafetyEnabled(false);
	// shootMotor->SetExpiration(.1);

	gateMotor = new CANTalon(GATE_MOTOR_ID);
	gateMotor->SetSafetyEnabled(false);
	// gateMotor->SetExpiration(.1);

	shooterCounter = new Counter(SHOOTER_COUNTER_DIO_PORT);
	shooterCounter->Reset();

	// Digital sonar. Third argument 0=inches, 1=millimeters
	/* Today's Headlines: Digital rangefinder baffles Programming Mentor... Tune in for details at 11
	rangeBoiler = new Ultrasonic(BOILER_RANGE_OUTPUT_PORT, BOILER_RANGE_INPUT_PORT, frc::Ultrasonic::DistanceUnit::kInches);
	rangeBoiler->SetAutomaticMode(true);
	/* */
	rangeBoiler = new AnalogInput(ROBORIO_ANALOG_ZERO);
	light = new Relay(LIGHT_BAR_RELAY_PORT);
}

void Shooter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new BoilerRangeLight());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Shooter::Shoot(double factor = 1.0)
{
	shootMotor->Set(-SHOOT_POWER * factor);
}
void Shooter::Stop()
{
	shootMotor->Set(0.0);
}
double Shooter::GetRPM()
{
	return 1/shooterCounter->GetPeriod() * 60.0; // return RPM
}
void Shooter::FeederStart()
{
	gateMotor->Set(1.0);
}
void Shooter::FeederStop()
{
	gateMotor->Set(0.0);
}

void Shooter::Light(unsigned int state)
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

float Shooter::GetAverageVoltage()
{
	return rangeBoiler->GetAverageVoltage();
}

float Shooter::GetRangeInches()
{
	return rangeBoiler->GetAverageVoltage() * IN_FACTOR;
}
