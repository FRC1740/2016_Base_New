#ifndef ExtendPiston_H
#define ExtendPiston_H

#include "../CommandBase.h"
#include "WPILib.h"

class ExtendPiston: public CommandBase
{
public:
	ExtendPiston();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
