#include "XBoxSaucer.h"
#include "../RobotMap.h"
#include "OI.h"
#include "math.h"

XBoxSaucer::XBoxSaucer()
{
	Requires(drivetrain);
	/* Arguments to RobotDrive must be in the following order
	 *     - 1 front left drive motor
	 *     - 2 rear left drive motor
	 *     - 3 front right drive motor
	 *     - 4 rear right drive motor
	 */
	m_robotDrive = new RobotDrive(drivetrain->front_left_motor, drivetrain->rear_left_motor,
									drivetrain->front_right_motor, drivetrain->rear_right_motor);

	// For some reason, these next lines also affect Xbox Standard drive.
	// Perhaps because they both inherit from the same class?
//	m_robotDrive->SetInvertedMotor(frc::RobotDrive::kFrontRightMotor, true);
//	m_robotDrive->SetInvertedMotor(frc::RobotDrive::kRearRightMotor, true);

	drivetrain->gyro->Reset();
	this->gyroAngle = 0.0;
}

void XBoxSaucer::Initialize()
{
	datalogger->Log("XBoxSaucer::Initialize()", STATUS_MESSAGE);
}

void XBoxSaucer::Execute()
{
	float currentGyroAngle = drivetrain->gyro->GetAngle();
	char log[128];

	datalogger->Log("XBoxSaucer::Execute()", VERBOSE_MESSAGE);

	// Experimental XBox "Saucer Mode" Uses gyro and RobotDrive->Mecanum() for absolute direction control

	if (abs(this->gyroAngle - currentGyroAngle) > 3)
	{
		this->gyroAngle = currentGyroAngle;
		sprintf(log, "XboxSaucer::Execute() gyroAngle now %f", this->gyroAngle);
		datalogger->Log(log, STATUS_MESSAGE);
		printf("gyroAngle now %f", this->gyroAngle);
	}

	// For auto steering, pass this->gyroAngle as the fourth argument
	m_robotDrive->MecanumDrive_Cartesian(this->GetX(), this->GetY(), this->GetTwist(), drivetrain->gyro->GetAngle());

}

// CRE 01-22-17 Added three methods to replicate 3-Axis Joystick
// CRE FIXME: I'm Guessing about the axis numbers...

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
