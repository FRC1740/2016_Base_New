#ifndef autoGroupGear_H
#define autoGroupGear_H

#include <Commands/CommandGroup.h>

// Angle to turn for respective gear placement
#define LEFTGEAR 35
#define RIGHTGEAR -47

class autoGroupGear : public CommandGroup
{
public:
	autoGroupGear(double angle);
};

#endif  // autoGroupGear_H
