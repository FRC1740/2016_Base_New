#include "DriveTrain.h"
#include "../RobotMap.h"
#include "math.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain")
{
	front_left_motor = new CANTalon(FRONT_LEFT_MOTOR_ID);
	front_right_motor = new CANTalon(FRONT_RIGHT_MOTOR_ID);
	rear_left_motor = new CANTalon(REAR_LEFT_MOTOR_ID);
	rear_right_motor = new CANTalon(REAR_RIGHT_MOTOR_ID);

	imu = new ADIS16448_IMU();
	imu->Reset();
	gyroAngle = 0.0;

	// CRE: 2017-02-17 Initialize the encoder position so we can (hopefully) tell how far we've moved
	front_left_motor->SetPosition(0);
	front_right_motor->SetPosition(0);
	rear_left_motor->SetPosition(0);
	rear_right_motor->SetPosition(0);
}

void DriveTrain::Go(float front_left_speed, float front_right_speed, float rear_left_speed, float rear_right_speed)
{

	// This drivetrain code assumes motors are mounted INBOARD and shafts point OUTBOARD
	// Left side motors fwd = robot fwd...
	front_left_motor->Set(front_left_speed);
	rear_left_motor->Set(rear_left_speed);

	// Invert the direction of the motors on the right side so motor reverse = robot fwd
	front_right_motor->Set(-1 * front_right_speed);
	rear_right_motor->Set(-1 * rear_right_speed);

	// CRE: 2017-02-17 This should show us if the encoder is working
	SmartDashboard::PutNumber("Wheel Position: ", rear_left_motor->GetPosition());
}

void DriveTrain::MoveTo(float distance, float angle=0.0)
{

}

void DriveTrain::SkateRight(float speed)
{
	front_left_motor->Set(speed);
	front_right_motor->Set(speed);
	rear_left_motor->Set(-speed);
	rear_right_motor->Set(-speed);

}
void DriveTrain::SkateLeft(float speed)
{
	front_left_motor->Set(-speed);
	front_right_motor->Set(-speed);
	rear_left_motor->Set(speed);
	rear_right_motor->Set(speed);
}
void DriveTrain::Stop()
{
	front_left_motor->Set(0);
	front_right_motor->Set(0);
	rear_left_motor->Set(0);
	rear_right_motor->Set(0);
}
