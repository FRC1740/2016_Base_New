#ifndef autoNothing_H
#define autoNothing_H

#include "../CommandBase.h"
#include "WPILib.h"

class autoNothing: public CommandBase
{
public:
	autoNothing(double);
	double timer;
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
