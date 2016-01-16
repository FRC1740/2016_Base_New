#ifndef Down_H
#define Down_H

#include "../CommandBase.h"
#include "WPILib.h"

class Down: public CommandBase
{
public:
	Down();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
