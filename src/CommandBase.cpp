#include "CommandBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static pointer/instance of all of your subsystems to NULL
OI* CommandBase::oi = NULL;
DriveTrain* CommandBase::drivetrain = NULL;
DataLogger* CommandBase::datalogger = NULL;
Piston*	CommandBase::piston = NULL;
Utility* CommandBase::utility = NULL;
Camera* CommandBase::camera = NULL;
Climber* CommandBase::climber = NULL;
Shooter* CommandBase::shooter = NULL;

CommandBase::CommandBase(char const *name): Command(name) {}

CommandBase::CommandBase(): Command() {}

void CommandBase::init()
{
	drivetrain = new DriveTrain();
	oi = new OI();
	datalogger = new DataLogger();
	piston = new Piston();
	camera = new Camera();
	utility = new Utility();
	climber = new Climber();
	shooter = new Shooter();
}
