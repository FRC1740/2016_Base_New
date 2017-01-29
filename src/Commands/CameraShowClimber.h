#ifndef CameraShowClimber_H
#define CameraShowClimber_H

#include "../CommandBase.h"

class CameraShowClimber : public CommandBase {
public:
	CameraShowClimber();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // CameraShowClimber_H
