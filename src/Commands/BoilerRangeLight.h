#ifndef BoilerRangeLight_H
#define BoilerRangeLight_H

#include "../CommandBase.h"

class BoilerRangeLight : public CommandBase {
public:
	BoilerRangeLight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // BoilerRangeLight_H
