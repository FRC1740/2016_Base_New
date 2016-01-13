#ifndef DriveTrain_H
#define DriveTrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveTrain: public Subsystem
{

public:
	DriveTrain();
	void InitDefaultCommand();
	Victor *front_right_motor;
	Victor *front_left_motor;
	Victor *rear_right_motor;
	Victor *rear_left_motor;
	void Go(float, float, float, float);
	void Stop();
};

#endif
