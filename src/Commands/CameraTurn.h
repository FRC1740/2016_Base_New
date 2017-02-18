#ifndef CameraTurn_H
#define CameraTurn_H

#include "../CommandBase.h"

class CameraTurn : public CommandBase {
public:
	CameraTurn(float);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	float Angle;
};

#endif  // CameraTurn_H
