#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:

public:
	OI();
	// Define all the input devices we may use
	Joystick *tankDriveJoystickLeft;
	Joystick *tankDriveJoystickRight;
	Joystick *threeAxisJoystick;
	Joystick *xboxController;
	Joystick *NESController;
	Joystick *launchPad;

	// Configure buttons which will perform specific tasks
	// The following rotate the camera
	JoystickButton *CameraTurnLeft;
	JoystickButton *CameraTurnRight;

	// Climber buttons up/down
	JoystickButton *climb;
	JoystickButton *descend;

	// Shoot a whiffle ball
	JoystickButton *shootXBox;
	JoystickButton *shoot3Axis;

	// Map buttons for turning in gear light
	JoystickButton *gearLightButtonXBox;
	JoystickButton *gearLightButton3Axis;

//	JoystickButton *threeAxis5;
//	JoystickButton *threeAxis6;
};

#endif
