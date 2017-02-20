#include <Commands/autoGroupShootRed.h>
#include "autoMoveToShootRange.h"
#include "autoShoot.h"
#include "autoSkate.h"

autoGroupShootRed::autoGroupShootRed()
{
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

	AddSequential(new autoSkate(LEFT, (float)0.2, (float)1.5)); // Direction/Speed/Distance (time)
	AddSequential(new autoMoveToShootRange());
	AddSequential(new autoShoot(10));
}
