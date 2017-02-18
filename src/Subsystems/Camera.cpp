#include "Camera.h"
#include "../RobotMap.h"
#include "../Commands/CameraShowGear.h" // YOU MUST INCLUDE IT to set it as the default command

Camera::Camera() : Subsystem("Camera")
{
		// Servo for rotating camera mount
		Mount = new Servo(9);
		ServoAngle = -1.0; // -1.0=left, 0.0=centered, 1.0=right
}

void Camera::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	// SetDefaultCommand(new CameraShowGear());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Camera::ShowGear()
{
	// Rotates the camera fully left
	ServoAngle = -1.0;
	Mount->Set(ServoAngle);
}

void Camera::ShowClimber()
{
	// Rotates the camera fully right
	ServoAngle = 1.0;
	Mount->Set(ServoAngle);
}

void Camera::ShowShooter()
{
	// Rotates the camera to be centered
	ServoAngle = 0.0;
	Mount->Set(ServoAngle);
}

void Camera::Center()
{
	ServoAngle = 0.0;
	Mount->Set(ServoAngle);
}

float Camera::GetPos()
{
	return ServoAngle;
}

bool Camera::CanTurnLeft()
{
	return ServoAngle > -1.0;
}
bool Camera::CanTurnRight()
{
	return ServoAngle < 1.0;
}

float Camera::TurnLeft()
{
	if (CanTurnLeft())
	{
		ServoAngle -= 1.0;
		Mount->Set(ServoAngle);
	}
	return ServoAngle;
}
float Camera::TurnRight()
{
	if (CanTurnRight())
	{
		ServoAngle += 1.0;
		Mount->Set(ServoAngle);
	}
	return ServoAngle;
}
