#include "Piston.h"

Piston::Piston() : Subsystem("Piston")
{
	s0 = new Solenoid(CYLINDER_PORT0);
	s1 = new Solenoid(CYLINDER_PORT1);
	isOpen = true;
}

void Piston::Extend()
{
	s0->Set(false);
	s1->Set(true);
	isOpen = true;
}

void Piston::Retract()
{
	isOpen = false;
	s0->Set(true);
	s1->Set(false);
}
