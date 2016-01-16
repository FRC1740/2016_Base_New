#include "Down.h"

Down::Down()
{
	Requires(utility);
}

void Down::Initialize()
{
	datalogger->Log("Down::Initialize()", STATUS_MESSAGE);
	utility->utility_motor->Set(-1 * SPEED);
}

void Down::Execute()
{
	return;
}

bool Down::IsFinished()
{
	return false;
}

void Down::End()
{
	datalogger->Log("Down::End()", ERROR_MESSAGE);
	utility->utility_motor->Set(0);
}

void Down::Interrupted()
{
	datalogger->Log("Down::Interrupted", STATUS_MESSAGE);
	utility->utility_motor->Set(0);
}
