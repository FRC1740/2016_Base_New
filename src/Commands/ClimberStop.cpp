#include "ClimberStop.h"

ClimberStop::ClimberStop() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(climber);
}

// Called just before this Command runs the first time
void ClimberStop::Initialize() {
	climber->stop();
//	printf("OK, Climber Stopped.");

}

// Called repeatedly when this Command is scheduled to run
void ClimberStop::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ClimberStop::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void ClimberStop::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ClimberStop::Interrupted() {
	climber->stop();
}
