#include <Commands/CameraShowClimber.h>
#include <Commands/CameraShowGear.h>
#include <Commands/Climb.h>
#include <Commands/Descend.h>
#include <Commands/Shoot.h>
#include <Commands/RangeLight.h>
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
	showClimber = new JoystickButton(xboxController, 5);
	showGear = new JoystickButton(xboxController, 6);

	showClimber->WhenPressed(new CameraShowClimber());
	showGear->WhenPressed(new CameraShowGear());

	// Shooter
	shoot = new JoystickButton(xboxController, 2);
	shoot->WhenPressed(new Shoot());

	// Climb & Descend
	climb = new JoystickButton(NESController, 2);
	descend = new JoystickButton(NESController, 3);

	climb->WhenPressed(new Climb());
	descend->WhenPressed(new Descend());

	// Light for "Gear Ready to Raise"
	gearLightButton = new JoystickButton(xboxController, 1);
	gearLightButton->WhenPressed(new GearLight);

	// Shooter
	shoot = new JoystickButton(xboxController, 2);
	shoot->WhenPressed(new Shoot());

}
