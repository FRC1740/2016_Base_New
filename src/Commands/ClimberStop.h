#ifndef ClimberStop_H
#define ClimberStop_H

#include "../CommandBase.h"

class ClimberStop : public CommandBase {
public:
	ClimberStop();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ClimberStop_H
