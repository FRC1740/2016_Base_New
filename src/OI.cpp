#include "OI.h"
#include "Commands/ExtendPiston.h"
#include "Commands/RetractPiston.h"
#include "Commands/Up.h"
#include "Commands/Down.h"

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

	threeAxis3 = new JoystickButton(threeAxisJoystick, 3);
	threeAxis4 = new JoystickButton(threeAxisJoystick, 4);
	threeAxis5 = new JoystickButton(threeAxisJoystick, 5);
	threeAxis6 = new JoystickButton(threeAxisJoystick, 6);

	threeAxis3->WhenPressed(new ExtendPiston());
	threeAxis4->WhenPressed(new RetractPiston());
	threeAxis5->WhileHeld(new Up());
	threeAxis6->WhileHeld(new Down());
}
