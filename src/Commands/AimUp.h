#ifndef AimUp_H
#define AimUp_H

#include "../CommandBase.h"

class AimUp : public CommandBase {
public:
	AimUp();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // AimUp_H
