#ifndef autoMoveDistance_H
#define autoMoveDistance_H

#include "../CommandBase.h"

#define FORWARD 1.0
#define REVERSE -1.0

#include "math.h"

#define WHEEL_DISTANCE_FACTOR M_PI/225

class autoMoveDistance : public CommandBase {
public:
	autoMoveDistance(float, float, float);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	float direction, speed, distance;
};

#endif  // autoMoveDistance_H
