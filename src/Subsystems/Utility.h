#ifndef Utility_H
#define Utility_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Utility: public Subsystem
{
public:
	Relay *gearLight;  // light to indicate gear is ready to remove
	Utility();
	void gearLightOn(); // Turn on the gear Light
	void gearLightOff(); // Turn off the gear Light
};

#endif
