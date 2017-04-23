#ifndef autoMoveDistance_H
#define autoMoveDistance_H

#include "../CommandBase.h"

#define FORWARD 0
#define REVERSE 180
#define RIGHT 90
#define LEFT -90

#include "math.h"

// #define WHEEL_DISTANCE_FACTOR 3.14159268/523
#define WHEEL_DISTANCE_FACTOR M_PI/523

class autoMoveDistance : public CommandBase {
public:
	autoMoveDistance(float, float, float);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	int angle;
	float speed, distance, left, right;
};

#endif  // autoMoveDistance_H
