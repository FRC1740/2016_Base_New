#include "autoMoveToShootRange.h"

#define TOWARD_BOILER -1.0
#define AWAY_FROM_BOILER 1.0

autoMoveToShootRange::autoMoveToShootRange() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrain);
	Requires(shooter);
	startingRange = shooter->GetRangeInches(); // Distance to boiler
	currentRange = startingRange;
	previousRange = currentRange;
	speed = 0.0;
}

// Called just before this Command runs the first time
void autoMoveToShootRange::Initialize() {

	if (startingRange < MIN_RANGE) // Move backward if we're too close
	{
		speed = .2 * AWAY_FROM_BOILER;
	}
	else if (startingRange > MAX_RANGE) // Move forward if we're not close enough
	{
		speed = .2 * TOWARD_BOILER;
	}
	SetTimeout(0.5); // Period to check distance
}

// Called repeatedly when this Command is scheduled to run
void autoMoveToShootRange::Execute() {

	drivetrain->Go(speed, speed, speed, speed);
	currentRange = shooter->GetRangeInches();
}

// Make this return true when this Command no longer needs to run execute()
bool autoMoveToShootRange::IsFinished() {

	if (MIN_RANGE < currentRange && currentRange < MAX_RANGE)
		return true;
	else
		return false;
}

// Called once after isFinished returns true
void autoMoveToShootRange::End() {
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void autoMoveToShootRange::Interrupted() {

}
