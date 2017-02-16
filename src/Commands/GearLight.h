#ifndef GearLight_H
#define GearLight_H

#include "../CommandBase.h"

class GearLight : public CommandBase {
public:
	GearLight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // GearLight_H
