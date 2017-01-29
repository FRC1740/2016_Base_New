#ifndef CameraShowGear_H
#define CameraShowGear_H

#include "../CommandBase.h"

class CameraShowGear : public CommandBase {
public:
	CameraShowGear();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // CameraShowGear_H
