#ifndef Shoot_H
#define Shoot_H

#include "../CommandBase.h"

#define OPTIMUM_SHOOTER_RPM (double)3200 // FIXME: Calibrate for actual 'bot

class Shoot : public CommandBase {
public:
	Shoot();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // Shoot_H
