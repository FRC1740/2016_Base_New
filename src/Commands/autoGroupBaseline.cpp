#include <Commands/autoGroupBaseline.h>

autoGroupBaseline::autoGroupBaseline()
{
	// Successful test of moving to baseline with testbed & 4" mecanum wheels using settings below.
	// AddSequential(new autoMove(0, .5, 3.0)); // move at 0 degrees (forward) at half speed for 3 seconds

	// Guesstimating that we need half the time since 8" mecanum wheels travel twice as far in one rev.
	AddSequential(new autoMove(0, .5, 2.0)); // move at 0 degrees (forward) at half speed for 2 seconds
}
