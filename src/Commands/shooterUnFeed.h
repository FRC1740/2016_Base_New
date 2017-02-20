#ifndef shooterUnFeed_H
#define shooterUnFeed_H

#include "../CommandBase.h"

class shooterUnFeed : public CommandBase {
public:
	shooterUnFeed();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // shooterUnFeed_H
