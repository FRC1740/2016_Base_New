#include "autoTurn.h"

autoTurn::autoTurn(double angle)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires (drivetrain);
	turnAngle = angle;
	if (angle < 0)
		direction = -1;
	else
		direction = 1;
	speed = 0;
	speedP = 0.0;
	speedI = 0.0;
	speedD = 0.0;
	gyroAngle = 0.0;
}

// Called just before this Command runs the first time
void autoTurn::Initialize()
{
	drivetrain->imu->Reset();
	gyroAngle = drivetrain->GetGyroAngle();
}

// Called repeatedly when this Command is scheduled to run
void autoTurn::Execute()
{
	gyroAngle = drivetrain->GetGyroAngle();
	// Positive Gyro Angle means we need to turn left and vice versa

	speedP = (fabs(turnAngle) - fabs(gyroAngle)) / fabs(turnAngle);
	speedI += speedP;
	speedD = 0.0;

	speed = kP * speedP + kI * speedI + kD * speedD;

	drivetrain->Go(speed * direction, speed * -direction, speed * direction, speed * -direction);
	printf("Turning @ %f (speedP = %f, speedI = %f.)\n", speed, speedP, speedI);
}

// Make this return true when this Command no longer needs to run execute()
bool autoTurn::IsFinished() {

	double keep_turning = abs(turnAngle) - abs(gyroAngle);

	if (keep_turning > 0) // Kid of kludgy. Real PID should handle this
		return false;
	else
		return true;
}

// Called once after isFinished returns true
void autoTurn::End()
{
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void autoTurn::Interrupted()
{
	drivetrain->Stop();
}
