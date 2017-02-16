#ifndef autoMoveToShootRange_H
#define autoMoveToShootRange_H

#include "../CommandBase.h"

class autoMoveToShootRange : public CommandBase {
public:
	autoMoveToShootRange();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	double speed, range;
};

#endif  // autoMoveToShootRange_H
