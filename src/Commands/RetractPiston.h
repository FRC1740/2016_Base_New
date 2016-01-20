#ifndef RetractPiston_H
#define RetractPiston_H

#include "../CommandBase.h"
#include "WPILib.h"

class RetractPiston: public CommandBase
{
public:
	RetractPiston();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
