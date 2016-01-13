#include "OI.h"

OI::OI()
{
	// Driver Station option A: Sticks 1 & 2 used for Tank Drive
		tankDriveJoystickLeft = new Joystick(1);
		tankDriveJoystickRight = new Joystick(2);
		// Driver Station option B: Stick 3 is 3-axis joystick
		threeAxisJoystick = new Joystick(3);
		// Driver Station option C: Stick 4 is Xbox controller
		xboxController = new Joystick(4);
		// Joystick 5 is the NES controller
		NESController = new Joystick(5);
		// Joystick 0 is the launchpad
		launchPad = new Joystick(0);
}
