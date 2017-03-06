#ifndef XBOXDRIVE_H
#define XBOXDRIVE_H

#include "../CommandBase.h"
#include "WPILib.h"

#define SCALE_TWIST 1.0 // Adjust these to suit drivers' preference
#define SCALE_YAXIS 1.0
#define SCALE_XAXIS 1.0
#define DEADBAND_XAXIS .1 // Adjust these to prevent unwanted movement when input at rest
#define DEADBAND_YAXIS .1
#define DEADBAND_TWIST .3

class XBoxDrive: public CommandBase
{
private:
public:
	XBoxDrive();
	float GetX();
	float GetY();
	float GetTwist();
	// Forward is normally toward gear
	bool reversed = false;
	float gfl = 0, gfr = 0, grl = 0, grr = 0; // Used to log/display motor outputs
	double saucerAngle;
	double prevAngle;
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
