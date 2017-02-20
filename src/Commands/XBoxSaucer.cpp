#include "XBoxSaucer.h"
#include "XBoxDrive.h"
#include "../RobotMap.h"
#include "OI.h"
#include "Math.h"

#define DEG_TO_RAD 3.14159268/180.0

/*
 * CRE: 2017-02-13
 * Adapted from XBoxDrive command, this mode is intended to use vector mapping of left joystick
 * in combination with the IMU gyro for absolute "saucer mode" directional movement, and
 * the right joystick mapping to turning left/right. We'll see...
 */

XBoxSaucer::XBoxSaucer()
{
	Requires(drivetrain);
	saucerAngle = 0.0;
	prevAngle = 0.0;
}

void XBoxSaucer::Initialize()
{
	datalogger->Log("XBoxSaucer::Initialize()", STATUS_MESSAGE);
	drivetrain->imu->Reset();
	saucerAngle = 0.0;
	prevAngle = 0.0;
}

void XBoxSaucer::Execute()
{
	char gyroString[128];

	saucerAngle = drivetrain->imu->GetAngleZ()/4.0;
	if (abs(saucerAngle  - prevAngle) > .1)
	{
		prevAngle = saucerAngle;
		printf("XBoxSaucer::Execute() saucerAngle = %5.2f\n", saucerAngle);
		sprintf(gyroString, "%5.2f degrees", saucerAngle);
		SmartDashboard::PutString("Gyro Angle: ", gyroString);
	}
	float x = 0, y = 0, t = 0; // floats for the axes x, y, twist
	float fl = 0, fr = 0, rl = 0, rr = 0; // floats for the motor outputs

	if (this->GetY() > DEADBAND_YAXIS || this->GetY() < -DEADBAND_YAXIS) // Deadband
	{
		y = SCALE_YAXIS * this->GetY() * sin(saucerAngle * DEG_TO_RAD);
	}
	if (this->GetX() > DEADBAND_XAXIS || this->GetX() < -DEADBAND_XAXIS)  // Deadband
	{
		x = SCALE_XAXIS * this->GetX() * cos(saucerAngle * DEG_TO_RAD);
	}
	if (this->GetTwist() > DEADBAND_TWIST || this->GetTwist() < -DEADBAND_TWIST)  // Deadband
	{
		t = SCALE_TWIST  * this->GetTwist();
	}
	fl =  y + t + x; // Front Left Wheel
	fr =  y - t - x; // Front Right Wheel
	rl =  y + t - x; // Rear Left Wheel
	rr =  y - t + x; // Rear Right Wheel

	// If movement has changed, log it...
	if (gfl!=fl || gfr!=fr || grl!=rl || grr!=rr)
	{
		gfl=fl; gfr=fr; grl=rl; grr=rr;
		char *data = new char[128];
		sprintf(data, "We're moving: %2.1f, %2.1f, %2.1f, %2.1f; X=%2.1f, Y=%2.1f, Twist=%2.1f", fl, fr, rl, rr, x, y, t);
		datalogger->Log(data, DEBUG_MESSAGE);
	}

	// The drivetrain->Go() method has built in handling for reversing motors on the left side...
	drivetrain->Go(fl,fr,rl,rr);
	// drivetrain->MecanumDrive(this->GetX(), this->GetY(), this->GetTwist());
}

// CRE 01-22-17 Added three methods to replicate 3-Axis Joystick
float XBoxSaucer::GetX()
{
	float input = oi->xboxController->GetRawAxis(0);

	if (abs(input) < DEADBAND_XAXIS)
		input = 0.0;

	return input;
}

float XBoxSaucer::GetY()
{
	float input = oi->xboxController->GetRawAxis(1);

	if (abs(input) < DEADBAND_YAXIS)
		input = 0.0;

	return input;
}

float XBoxSaucer::GetTwist()
{
	float input = oi->xboxController->GetRawAxis(4);

	if (abs(input) < DEADBAND_TWIST)
		input = 0.0;

	return input;
}

bool XBoxSaucer::IsFinished()
{
	return false;
}

void XBoxSaucer::End()
{
	datalogger->Log("XBoxSaucer::End()", ERROR_MESSAGE);
	drivetrain->Stop();
}

void XBoxSaucer::Interrupted()
{
	datalogger->Log("XBoxSaucer::Interrupted()", STATUS_MESSAGE);
	drivetrain->Stop();
}
