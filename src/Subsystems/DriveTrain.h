#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
// FIXME: FATAL - Can't Find CANTalonSRX class. Using CANTalon.h
#include "ADIS16448_IMU.h"
#include <CANTalon.h>

class DriveTrain: public Subsystem
{

public:
	CANTalon *front_right_motor;
	CANTalon *front_left_motor;
	CANTalon *rear_right_motor;
	CANTalon *rear_left_motor;
	ADIS16448_IMU *imu;
	double gyroAngle;
	bool reversed;
	DriveTrain();
	void Go(float, float, float, float);
	// Hoping to use this for encoder-feedback auto-move
	// arg1: distance, arg2: angle
	void MoveTo(float, float);
	void SkateRight(float);
	void SkateLeft(float);
	void ReverseDirection(void);
	void Stop();
};

#endif
