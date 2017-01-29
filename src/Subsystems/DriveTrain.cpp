#include "DriveTrain.h"
#include "../RobotMap.h"
// #include "ADIS16448_IMU.h"
#include "math.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain")
{
	front_left_motor = new CANTalon(FRONT_LEFT_MOTOR_ID);
	front_right_motor = new CANTalon(FRONT_RIGHT_MOTOR_ID);
	rear_left_motor = new CANTalon(REAR_LEFT_MOTOR_ID);
	rear_right_motor = new CANTalon(REAR_RIGHT_MOTOR_ID);

	gyro = new AnalogGyro(DRIVE_GYRO_PORT);
	gyro->Reset();

	// New Inertial Measurement Unit for 2017. Plugs directly into RoboRio. Woo hoo!
//	imu = new ADIS16448_IMU;

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
}

void DriveTrain::Stop()
{
	front_left_motor->Set(0);
	front_right_motor->Set(0);
	rear_left_motor->Set(0);
	rear_right_motor->Set(0);
}
