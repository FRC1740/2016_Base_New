#ifndef Utility_H
#define Utility_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

#define SPEED 1.0

class Utility: public Subsystem
{
public:
	TalonSRX *utility_motor;
	Utility();
};

#endif
