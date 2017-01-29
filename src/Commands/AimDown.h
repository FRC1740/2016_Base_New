#ifndef AimDown_H
#define AimDown_H

#include "../CommandBase.h"

class AimDown : public CommandBase {
public:
	AimDown();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AimDown_H
