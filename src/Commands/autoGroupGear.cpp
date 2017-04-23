#include "autoGroupGear.h"
#include "autoMove.h"
#include "autoTurn.h"

autoGroupGear::autoGroupGear(double angle)
{
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	AddSequential(new autoMove(0, .4, 1.925));
	AddSequential(new autoTurn(angle));
	AddSequential(new autoMove(0, .4, .93));

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
}
