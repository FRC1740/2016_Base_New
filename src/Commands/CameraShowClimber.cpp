#include <Commands/CameraShowClimber.h>

CameraShowClimber::CameraShowClimber(){
//	Requires(camera);
}

// Called just before this Command runs the first time
void CameraShowClimber::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void CameraShowClimber::Execute() {

//	camera->ShowClimber();
	return;
}

// Make this return true when this Command no longer needs to run execute()
bool CameraShowClimber::IsFinished() {
	return(true);
}

// Called once after isFinished returns true
void CameraShowClimber::End() {
	return;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CameraShowClimber::Interrupted() {

}
