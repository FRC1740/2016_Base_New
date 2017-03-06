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
	// JoystickButton *CameraTurnLeft;
	// JoystickButton *CameraTurnRight;

	// Climber buttons up/down
	JoystickButton *climb;
	JoystickButton *descend;
	JoystickButton *shoot;
	JoystickButton *door;

	// Shoot a whiffle ball
	JoystickButton *XBoxLeftBumper;
	JoystickButton *XBoxRightBumper;
	JoystickButton *ThreeAxisTrigger;

	// Reverse Drive Direction
	JoystickButton *XBoxYButton;

	// Button mapping for door solenoid open/close
	// Map buttons for turning in gear light
	JoystickButton *gearLightButtonXBox;
	JoystickButton *gearLightButton3Axis;
//	JoystickButton *threeAxis5;
//	JoystickButton *threeAxis6;
};

#endif
