#ifndef XBoxSaucer_H
#define XBoxSaucer_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "../ADIS16448_IMU.h"

#define SCALE_TWIST 1.0 // Adjust these to suit drivers' preference
#define SCALE_YAXIS 1.0
#define SCALE_XAXIS 1.0
#define DEADBAND_XBOX_XAXIS .05 // Adjust these to prevent unwanted movement when input at rest
#define DEADBAND_XBOX_YAXIS .05
#define DEADBAND_XBOX_TWIST .1

class XBoxSaucer: public CommandBase
{
private:
public:
	XBoxSaucer();
	float GetX();
	float GetY();
	float GetTwist();
	float gfl = 0, gfr = 0, grl = 0, grr = 0; // Used to log/display motor outputs
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	ADIS16448_IMU *imu;
	CANTalon *front_left_motor;
	CANTalon *rear_left_motor;
	CANTalon *front_right_motor;
	CANTalon *rear_right_motor;
	RobotDrive *saucerDrive;		// RobotDrive object using four individual drive motors
	double saucerAngle;
};

#endif
