#ifndef autoShoot_H
#define autoShoot_H

#include "../CommandBase.h"

class autoShoot : public CommandBase {
public:
	autoShoot(double);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // autoShoot_H
