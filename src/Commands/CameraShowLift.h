#ifndef CameraShowLift_H
#define CameraShowLift_H

#include "../CommandBase.h"

class CameraShowLift : public CommandBase {
public:
	CameraShowLift();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // CameraShowLift_H
