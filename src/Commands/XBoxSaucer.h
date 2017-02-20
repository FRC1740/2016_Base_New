#ifndef XBoxSaucer_H
#define XBoxSaucer_H

#include "../CommandBase.h"
#include "WPILib.h"

class XBoxSaucer: public CommandBase
{
private:
public:
	XBoxSaucer();
	float GetX();
	float GetY();
	float GetTwist();
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
