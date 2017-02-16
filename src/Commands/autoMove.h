#ifndef autoMove_H
#define autoMove_H

#include "WPILib.h"
#include "../CommandBase.h"
#include "../RobotMap.h"

class autoMove: public CommandBase
{
public:
	autoMove(int, float, double);
	int angle;
	float speed, left, right;
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
