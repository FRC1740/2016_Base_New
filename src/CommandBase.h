#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <string>
#include "Commands/Command.h"
#include "OI.h"
#include "WPILib.h"
#include "Subsystems/Utility.h"
#include "Subsystems/Piston.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/RangeFinder.h"
#include "Subsystems/DataLogger.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command
{
public:
	CommandBase(char const *name);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static OI *oi;
	static DataLogger *datalogger;
	static DriveTrain *drivetrain;
	static Piston *piston;
	static Utility *utility;
	static RangeFinder *rangefinder;
};

#endif
