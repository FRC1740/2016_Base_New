#include "CameraShowGear.h"

CameraShowGear::CameraShowGear() {
	Requires(camera);
}

// Called just before this Command runs the first time
void CameraShowGear::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void CameraShowGear::Execute() {

	camera->Gear();
	return;
}

// Make this return true when this Command no longer needs to run execute()
bool CameraShowGear::IsFinished() {

	return true;
}

// Called once after isFinished returns true
void CameraShowGear::End() {

	return;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CameraShowGear::Interrupted() {

}
