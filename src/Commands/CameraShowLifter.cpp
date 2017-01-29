#include "CameraShowLift.h"

CameraShowLift::CameraShowLift(){
	Requires(camera);
}

// Called just before this Command runs the first time
void CameraShowLift::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void CameraShowLift::Execute() {

	camera->Lift();
	return;
}

// Make this return true when this Command no longer needs to run execute()
bool CameraShowLift::IsFinished() {
	return(true);
}

// Called once after isFinished returns true
void CameraShowLift::End() {
	return;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CameraShowLift::Interrupted() {

}
