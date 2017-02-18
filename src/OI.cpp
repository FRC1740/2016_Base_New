#include <Commands/CameraShowClimber.h>
#include <Commands/CameraShowGear.h>
#include <Commands/Climb.h>
#include <Commands/Descend.h>
#include <Commands/Shoot.h>
#include <Commands/BoilerRangeLight.h>
#include <Commands/GearLight.h>
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

	// Camera Rotation
	CameraTurnLeft = new JoystickButton(xboxController, 5);
	CameraTurnRight = new JoystickButton(xboxController, 6);

//	CameraTurnLeft->WhenPressed(new CameraTurn(-1.0)); // Turn Left
//	CameraTurnRight->WhenPressed(new CameraTurn(1.0)); // Turn Right

	// Shooter
	shootXBox = new JoystickButton(xboxController, 2);
	shootXBox->ToggleWhenPressed(new Shoot());
	shoot3Axis = new JoystickButton(threeAxisJoystick, 1);
	shoot3Axis->ToggleWhenPressed(new Shoot());

	// Climb & Descend
	climb = new JoystickButton(NESController, 2);
	descend = new JoystickButton(NESController, 3);

	climb->WhenPressed(new Climb());
	descend->WhenPressed(new Descend());

	// Light for "Gear Ready to Raise"
	gearLightButtonXBox = new JoystickButton(xboxController, 1);
	gearLightButtonXBox->WhileHeld(new GearLight);
	gearLightButton3Axis = new JoystickButton(threeAxisJoystick, 3);
	gearLightButton3Axis->WhileHeld(new GearLight);
}
