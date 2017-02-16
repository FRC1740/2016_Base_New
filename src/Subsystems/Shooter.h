#ifndef Shooter_H
#define Shooter_H

#include <Commands/Subsystem.h>
#include <CanTalon.h>
#include "Encoder.h"

class Shooter : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	CANTalon *shootMotor;
	CANTalon *gateMotor;
	Counter *shooterCounter;

public:
	Shooter();
	void InitDefaultCommand();
	void shoot();
	void shootStop();
	double getRPM(); // Show shooter RPM
	// Tank -> Shooter Gate
	void breachOpen();
	void breachClose();
};

#endif  // Shooter_H
