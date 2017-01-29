#include "Climber.h"
#include "../RobotMap.h"

Climber::Climber() : Subsystem("Climber") {

	climberMotor = new CANTalon(CLIMBER_MOTOR_ID);
}

void Climber::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	// SetDefaultCommand(new ClimberStop());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Climber::climb() {

	climberMotor->Set(-1.0);
}

void Climber::descend() {

	climberMotor->Set(1.0);
}

void Climber::stop() {

	this->go(0);
}

void Climber::go(float speed) {

	climberMotor->Set(speed);
}
