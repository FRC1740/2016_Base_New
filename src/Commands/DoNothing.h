#ifndef DONOTHING_H
#define DONOTHING_H

#include "../CommandBase.h"
#include "WPILib.h"

class DoNothing: public CommandBase
{
public:
	DoNothing(double);
	double timer;
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
