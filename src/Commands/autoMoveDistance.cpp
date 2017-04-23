#include "autoMoveDistance.h"

autoMoveDistance::autoMoveDistance(float a, float s, float dist)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(drivetrain);
	angle = a;
	speed = s;
	distance = dist;
	left = 1.0;
	right = 1.0;
}

// Called just before this Command runs the first time
void autoMoveDistance::Initialize()
{
	drivetrain->imu->Reset();
}

// Called repeatedly when this Command is scheduled to run
void autoMoveDistance::Execute()
{
	// Adjust angle based on imu feedback
	angle -= ((int)(drivetrain->imu->GetAngleZ()/4.0) % 360);

	/*
	 * This code was designed to autocorrect for a slight "pull" to the left or right.
	 * it works, but does not allow us to "skate" at an angle.
	 *
	 * Moreover, it does appear to allow us to turn the 'bot to a substantial angle
	 * in autonomous mode if we need to do so.
	 *
	 * For example, the command autoMove(45, .5, 1.5) caused the testbed with
	 * 4" mecanum wheels to turn right for 1.5 seconds resulting an a right hand
	 * turn of about 60 degrees. The first argument (angle) of 45, just means the
	 * right side wheels are basically stopped. Did not try any other angles.
	 */


	// TODO there must be a nicer way to do this, but this works -ktk
	if (angle <= 90){
		left = 1;
		right = (((90.0 - angle) / 90.0) * 2) - 1; // do some range shifting to make it a float between -1 and 1
	}
	else if (90 < angle and angle < 180){
		left = (((180.0 - angle) / 90.0) * 2) - 1;
		right = -1;
	}
	else if (180 <= angle and angle <= 270){
		left = -1;
		right = (((270.0 - angle) / 90.0) * -2) + 1;
	}
	else if (angle < 360){
		left = (((360.0 - angle) / 90.0) * -2) + 1;
		right = 1;
	}

	// The drivetrain->Go method has built-in reversal for motors on "wrong" side
	drivetrain->Go(left * speed, right * speed, left * speed, right * speed);
	return;
}

// Make this return true when this Command no longer needs to run execute()
bool autoMoveDistance::IsFinished()
{
	double flDist, rlDist, frDist, rrDist;

	// Use the following return value for timed movement
	// return IsTimedOut();

	// Use encoder feedback to determine when to stop.
	flDist = abs(drivetrain->front_left_motor->GetPosition() * WHEEL_DISTANCE_FACTOR);
	rlDist = abs(drivetrain->rear_left_motor->GetPosition() * WHEEL_DISTANCE_FACTOR);
	// Presently only left side encoders working
	// frDist = abs(drivetrain->front_right_motor->GetPosition() * WHEEL_DISTANCE_FACTOR);
	// rrDist = abs(drivetrain->rear_right_motor->GetPosition() * WHEEL_DISTANCE_FACTOR);
	if (flDist >= this->distance && rlDist >= this->distance)
	{
		return true;
	}
	else
	{
		return false;
	}

	return false;
}

// Called once after isFinished returns true
void autoMoveDistance::End()
{
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void autoMoveDistance::Interrupted() {

}
