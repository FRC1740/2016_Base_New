#ifndef autoSkateLeft_H
#define autoSkateLeft_H

#include "../CommandBase.h"

class autoSkateLeft : public CommandBase {
public:
	autoSkateLeft();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // autoSkateLeft_H
