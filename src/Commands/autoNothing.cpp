#include <Commands/autoNothing.h>

autoNothing::autoNothing(double input)
{
	timer = input;
}
void autoNothing::Initialize()
{
	SetTimeout(timer);
}
void autoNothing::Execute()
{
	return;
}
bool autoNothing::IsFinished()
{
	return IsTimedOut();
}
void autoNothing::End()
{
	return;
}
void autoNothing::Interrupted()
{
	return;
}
