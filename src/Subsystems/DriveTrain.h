#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <TalonSRX.h>

class DriveTrain: public Subsystem
{
public:
	TalonSRX *front_right_motor;
	TalonSRX *front_left_motor;
	TalonSRX *rear_right_motor;
	TalonSRX *rear_left_motor;
	DriveTrain();
	void Go(float, float, float, float);
	void Stop();
};

#endif
