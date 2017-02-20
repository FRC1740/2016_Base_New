#include "XBoxDrive.h"
#include "../RobotMap.h"
#include "OI.h"
#include "math.h"

/*
 * XBox Controller uses three axes very much like a 3 Axis joystick.
 * Axis 0 = Left Stick X Axis (Move/Strafe Left/Right)
 * Axis 1 = Left Stick Y Axis (Move Fwd/Rev)
 * Axis 4 = Right Stick X Axis (Turn/twist Left/Right)
 */

XBoxDrive::XBoxDrive()
{
	Requires(drivetrain);
	saucerAngle = 0.0;
	prevAngle = 0.0;
}

void XBoxDrive::Initialize()
{
	datalogger->Log("XBoxDrive::Initialize()", STATUS_MESSAGE);
	drivetrain->imu->Reset();
	saucerAngle = 0.0;
	prevAngle = 0.0;
}

void XBoxDrive::Execute()
{
	char gyroString[128];

	datalogger->Log("XBoxDrive::Execute()", VERBOSE_MESSAGE);

	saucerAngle = drivetrain->imu->GetAngleZ()/4.0;
	if (abs(saucerAngle  - prevAngle) > .1)
	{
		prevAngle = saucerAngle;
		printf("XBoxDrive::Execute() saucerAngle = %5.2f\n", saucerAngle);
		sprintf(gyroString, "%5.2f degrees", saucerAngle);
		SmartDashboard::PutString("Gyro Angle: ", gyroString);
	}

	float x = 0, y = 0, t = 0; // floats for the axes x, y, twist
	float fl = 0, fr = 0, rl = 0, rr = 0; // floats for the motor outputs

	if (this->GetY() > DEADBAND_YAXIS || this->GetY() < -DEADBAND_YAXIS) // Deadband
	{
		y = SCALE_YAXIS * this->GetY();
	}
	if (this->GetX() > DEADBAND_XAXIS || this->GetX() < -DEADBAND_XAXIS)  // Deadband
	{
		x = SCALE_XAXIS * this->GetX();
	}
	if (this->GetTwist() > DEADBAND_TWIST || this->GetTwist() < -DEADBAND_TWIST)  // Deadband
	{
		t = SCALE_TWIST  * this->GetTwist();
	}
	fl = - y + t + x; // Front Left Wheel
	fr = - y - t - x; // Front Right Wheel
	rl = - y + t - x; // Rear Left Wheel
	rr = - y - t + x; // Rear Right Wheel

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
// CRE 02-13-17 Attempting to vectorize left joystick input
// CRE 01-22-17 Added three methods to replicate 3-Axis Joystick
float XBoxDrive::GetX()
{
	return oi->xboxController->GetRawAxis(0);
}

float XBoxDrive::GetY()
{
	return oi->xboxController->GetRawAxis(1);
}

float XBoxDrive::GetTwist()
{
	return oi->xboxController->GetRawAxis(4);
}

bool XBoxDrive::IsFinished()
{
	return false;
}

void XBoxDrive::End()
{
	datalogger->Log("XBoxDrive::End()", ERROR_MESSAGE);
	drivetrain->Stop();
}

void XBoxDrive::Interrupted()
{
	datalogger->Log("XBoxDrive::Interrupted()", STATUS_MESSAGE);
	drivetrain->Stop();
}
