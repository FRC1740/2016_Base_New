#ifndef autoTurn_H
#define autoTurn_H

#include "../CommandBase.h"

#define kP .4	// Proportional speed constant
#define kI .001	// Integral speed constant
#define kD 1.0	// Derivative speed constant

class autoTurn : public CommandBase {
public:
	double turnAngle;
	double gyroAngle;
	double direction;
	double speed;
	double speedP; // proportional speed factor
	double speedI; // integral speed factor
	double speedD; // derivative speed factor
	autoTurn(double angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // autoTurn_H
