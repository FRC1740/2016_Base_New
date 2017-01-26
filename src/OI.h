#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:

public:
	OI();
	Joystick *tankDriveJoystickLeft;
	Joystick *tankDriveJoystickRight;
	Joystick *threeAxisJoystick;
	Joystick *xboxController;
	Joystick *NESController;
	Joystick *launchPad;
	JoystickButton *lookAtLift;
	JoystickButton *lookAtGear;
//	JoystickButton *threeAxis5;
//	JoystickButton *threeAxis6;
};

#endif
