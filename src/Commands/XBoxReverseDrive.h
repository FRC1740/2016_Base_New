#ifndef XBoxReverseDrive_H
#define XBoxReverseDrive_H

#include "../CommandBase.h"

class XBoxReverseDrive : public CommandBase {
public:
	XBoxReverseDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // XBoxReverseDrive_H
