#ifndef moveAbsolute_H
#define moveAbsolute_H

#include "WPILib.h"
#include "../CommandBase.h"
#include "../RobotMap.h"

class moveAbsolute : public CommandBase
{
private:
	double speed;

public:
	moveAbsolute(double, double);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // moveAbsolute_H
