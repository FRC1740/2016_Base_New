#include "autoGroupShootBlue.h"
#include "autoMoveToShootRange.h"
#include "autoSkate.h"
#include "autoShoot.h"

autoGroupShootBlue::autoGroupShootBlue() {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
	// Here is what we need to do
	// First Ensure we are in position to shoot
	// Skate Left at 40% speed to a distance of 24 inches

	// AddSequential(new autoSkate(LEFT, (float)0.4, (float)48));
	// Check range to boiler & move forward/back as necessary
	// AddSequential(new autoMoveToShootRange());
	// Spin up & shoot
	AddSequential(new autoShoot(9.5));
}
