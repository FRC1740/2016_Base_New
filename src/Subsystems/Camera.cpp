#include "Camera.h"
#include "../RobotMap.h"
#include "../Commands/CameraShowGear.h" // YOU MUST INCLUDE IT to set it as the default command

Camera::Camera() : Subsystem("Camera")
{
		// Servo for rotating camera mount
		Mount = new Servo(9);
		Angle = 0.5;
}

void Camera::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	// SetDefaultCommand(new CameraShowGear());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Camera::showGear()
{
	// Rotates the camera fully right
	Mount->Set(1.0);
}

void Camera::showClimber()
{
	// Rotates the camera to be centered
	Mount->Set(0.5);
}

void Camera::showShooter()
{
	// Rotates the camera fully left
	Mount->Set(0.0);
}

void Camera::Center()
{
	Mount->Set(0.5);
}
