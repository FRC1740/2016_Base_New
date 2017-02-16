#ifndef pidGyroDrive_H
#define pidGyroDrive_H

#include "WPILib.h"
#include <Commands/PIDSubsystem.h>
#include <CANTalon.h>
#include "ADIS16448_IMU.h"

class pidGyroDrive : public PIDSubsystem {

private:
	// AnalogInput *rangeBoiler;

	RobotDrive *autobot; // Experimental; Autonomous mode only?
	CANTalon *front_left_motor;
	CANTalon *rear_left_motor;
	CANTalon *front_right_motor;
	CANTalon *rear_right_motor;

	// New Inertial Measurement Unit for 2017. Plugs directly into RoboRio. Woo hoo!
	ADIS16448_IMU *imu;

public:
	pidGyroDrive();
	void autoMove(double speed); // Move forward at speed
	void stop();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();
};

#endif  // pidGyroDrive_H
