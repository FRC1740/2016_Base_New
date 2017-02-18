#ifndef Shooter_H
#define Shooter_H

#include <Commands/Subsystem.h>
#include <CANTalon.h>
#include "../RobotMap.h"
#include "Encoder.h"

#define SHOOT_POWER -0.6	 	// Starting power for calibrated distance to target

// Calibrated based on measured distance
#define IN_FACTOR 1 / .00625
#define FT_FACTOR IN_FACTOR / 12

class Shooter : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	CANTalon *shootMotor;
	CANTalon *gateMotor;
	Counter *shooterCounter;
	Relay *light;
	AnalogInput *rangeBoiler;

public:
	Shooter();
	void InitDefaultCommand();
	void Shoot(double); // power multiplier
	void Stop();
	double GetRPM(); // Show shooter RPM
	// Tank -> Shooter Gate
	void FeederStart();
	void FeederStop();
	void Light(unsigned int); // Target within range indicator
	float GetAverageVoltage(void); // rangefinder
	float GetRangeInches(void); // Distance to boiler
};

#endif  // Shooter_H
