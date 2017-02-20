#ifndef shooterDoorOpen_H
#define shooterDoorOpen_H

#include "../CommandBase.h"

class shooterDoorOpen : public CommandBase {
public:
	shooterDoorOpen();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // shooterDoorOpen_H
