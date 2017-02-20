#ifndef shooterFeed_H
#define shooterFeed_H

#include "../CommandBase.h"

class shooterFeed : public CommandBase {
public:
	shooterFeed();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // shooterFeed_H
