#ifndef Shooter_H
#define Shooter_H

#include <Commands/Subsystem.h>
#include <CanTalon.h>

class Shooter : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	CANTalon *shootMotor;
	CANTalon *gateMotor;

public:
	Shooter();
	void InitDefaultCommand();
	void shoot();
	void shootStop();
	// Tank -> Shooter Gate
	void breachOpen();
	void breachClose();
};

#endif  // Shooter_H
