#ifndef Shooter_H
#define Shooter_H

#include <Commands/Subsystem.h>
#include <CanTalon.h>

class Shooter : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	CANTalon *shootMotor;
	CANTalon *aimMotor;

public:
	Shooter();
	void InitDefaultCommand();
	void aimUp();
	void aimDn();
	void aimStop();
	void aim(float speed);
	void shoot();
	void shootStop();
};

#endif  // Shooter_H
