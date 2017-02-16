#include "XBoxSaucer.h"
#include "../RobotMap.h"
#include "OI.h"

/*
 * CRE: 2017-02-13
 * Adapted from XBoxDrive command, this mode is intended to use vector mapping of left joystick
 * in combination with the IMU gyro for absolute "saucer mode" directional movement, and
 * the right joystick mapping to turning left/right. We'll see...
 */

// XBox Controller uses three axes very much like a 3 Axis joystick.
// Axis 0 = Left Stick X Axis (Move/Strafe Left/Right)
// Axis 1 = Left Stick Y Axis (Move Fwd/Rev)
// Axis 4 = Right Stick X Axis (Turn/twist Left/Right)


XBoxSaucer::XBoxSaucer()
{
//	Requires(drivetrain);
	front_left_motor = new CANTalon(FRONT_LEFT_MOTOR_ID);
	rear_left_motor = new CANTalon(REAR_LEFT_MOTOR_ID);
	front_right_motor = new CANTalon(FRONT_RIGHT_MOTOR_ID);
	rear_right_motor = new CANTalon(REAR_RIGHT_MOTOR_ID);

	saucerAngle = 0.0;
	saucerDrive = new RobotDrive(front_left_motor, rear_left_motor, front_right_motor, rear_right_motor);
	imu = new ADIS16448_IMU;

}

void XBoxSaucer::Initialize()
{
	datalogger->Log("XBoxSaucer::Initialize()", STATUS_MESSAGE);
	imu->Reset();
}

void XBoxSaucer::Execute()
{
	double oiInputAngle, inputX, inputY, inputMag;
	char gyroString[128];

	saucerAngle = -imu->GetAngleZ()/4.0;
	sprintf(gyroString, "%5.2f degrees", saucerAngle);
//	SmartDashboard::PutString("Gyro Angle: ", gyroString);
	sprintf(gyroString, "XBoxSaucer::Execute() saucerAngle = %5.2f", saucerAngle);
	datalogger->Log(gyroString, VERBOSE_MESSAGE);

	inputX = GetX();
	inputY = GetY();

	if (inputX == 0.0 && inputY == 0.0)
	{
		saucerDrive->StopMotor();
	}
	else
	{
		oiInputAngle =  atan(-inputX/inputY);
		if (inputY > 0) // Driver wants to go toward home alliance station
		{
			oiInputAngle += 180;
		}
		inputMag = sqrt(pow(inputX,2) + pow(inputY,2));
		saucerDrive->MecanumDrive_Polar(inputMag, oiInputAngle, saucerAngle);
	}
}

// CRE 01-22-17 Added three methods to replicate 3-Axis Joystick
float XBoxSaucer::GetX()
{
	float input = oi->xboxController->GetRawAxis(0);

	if (abs(input) < DEADBAND_XBOX_XAXIS)
		input = 0.0;

	return input;
}

float XBoxSaucer::GetY()
{
	float input = oi->xboxController->GetRawAxis(1);

	if (abs(input) < DEADBAND_XBOX_YAXIS)
		input = 0.0;

	return input;
}

float XBoxSaucer::GetTwist()
{
	float input = oi->xboxController->GetRawAxis(4);

	if (abs(input) < DEADBAND_XBOX_TWIST)
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
