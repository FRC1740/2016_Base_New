#ifndef Utility_H
#define Utility_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

#define SPEED 1.0

class Utility: public Subsystem
{
public:
	Relay *gearLight;  // light to indicate gear is ready to remove
	Utility();
	void gearLightOn(); // Turn on the gear Light
	void gearLightOff(); // Turn off the gear Light
};

#endif
