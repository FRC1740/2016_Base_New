#ifndef autoSkate_H
#define autoSkate_H

#define LEFT 1.0
#define RIGHT -1.0

#include "../CommandBase.h"

class autoSkate : public CommandBase {
public:
	autoSkate(float, float, float);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	float direction, speed;
};

#endif  // autoSkate_H
