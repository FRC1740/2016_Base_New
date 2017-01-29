#ifndef THREEAXISDRIVE_H
#define THREEAXISDRIVE_H

#include "math.h"
#include "../CommandBase.h"
#include "WPILib.h"

#define JOYSTICK_SCALE_TWIST 0.4 // Adjust SCALE values according to drivers' preference
#define SCALE_YAXIS 1.0
#define SCALE_XAXIS 1.0
#define DEADBAND_XAXIS .1 // Adjust to prevent unwanted movement when input at rest
#define DEADBAND_YAXIS .1
#define DEADBAND_TWIST .3

class ThreeAxisDrive: public CommandBase
{
public:
	ThreeAxisDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	float gfl = 0, gfr = 0, grl = 0, grr = 0; // Used to log/display the motor outputs
};

#endif
