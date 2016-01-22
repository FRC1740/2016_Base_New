#include "ExtendPiston.h"

ExtendPiston::ExtendPiston()
{
	Requires(piston);
}

void ExtendPiston::Initialize()
{
	datalogger->Log("ExtendPiston::Initialize()", DEBUG_MESSAGE);
	piston->Extend();
}

void ExtendPiston::Execute()
{
	return;
}

bool ExtendPiston::IsFinished()
{
	return true;
}

void ExtendPiston::End()
{
	datalogger->Log("ExtendPiston::End()", DEBUG_MESSAGE);
}

void ExtendPiston::Interrupted()
{
	datalogger->Log("ExtendPiston::Interrupted()", ERROR_MESSAGE);
}
