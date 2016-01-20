#include "RetractPiston.h"

RetractPiston::RetractPiston()
{
	Requires(piston);
}

void RetractPiston::Initialize()
{
	datalogger->Log("RetractPiston::Initialize()", DEBUG_MESSAGE);
	piston->Retract();
}

void RetractPiston::Execute()
{
	return;
}

bool RetractPiston::IsFinished()
{
	return true;
}

void RetractPiston::End()
{
	datalogger->Log("RetractPiston::End()", DEBUG_MESSAGE);
}

void RetractPiston::Interrupted()
{
	datalogger->Log("RetractPiston::Interrupted()", ERROR_MESSAGE);
}
