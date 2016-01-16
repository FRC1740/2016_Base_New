#ifndef Up_H
#define Up_H

#include "../CommandBase.h"
#include "WPILib.h"

class Up: public CommandBase
{
public:
	Up();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
