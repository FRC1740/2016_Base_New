#include "Up.h"

Up::Up()
{
	Requires(utility);
}

void Up::Initialize()
{
	datalogger->Log("Up::Initialize()", STATUS_MESSAGE);
	utility->utility_motor->Set(SPEED);
}

void Up::Execute()
{
	return;
}

bool Up::IsFinished()
{
	return false;
}

void Up::End()
{
	datalogger->Log("Up::End()", ERROR_MESSAGE);
	utility->utility_motor->Set(0);
}

void Up::Interrupted()
{
	datalogger->Log("Up::Interrupted", STATUS_MESSAGE);
	utility->utility_motor->Set(0);
}
