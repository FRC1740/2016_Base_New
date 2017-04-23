#include <Commands/autoMove.h>

autoMove::autoMove(int a, float s, double time)
{
	Requires(drivetrain);
	speed = s;
	angle = a % 360; // simplify angle
	left = 1.0;
	right = 1.0;
	SetTimeout(time);

	// DIAGONALS ALWAYS MATCH WITH MECANUM, base everything on the front

}

void autoMove::Initialize()
{
	drivetrain->imu->Reset();
}

void autoMove::Execute()
{

	// Adjust angle based on imu feedback
//	angle = (int)drivetrain->GetGyroAngle();
	angle = 0;
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

bool autoMove::IsFinished()
{
	return IsTimedOut();
}

void autoMove::End()
{
	drivetrain->Stop();
}

void autoMove::Interrupted()
{
	drivetrain->Stop();
}
