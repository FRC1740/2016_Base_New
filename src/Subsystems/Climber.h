#ifndef Climber_H
#define Climber_H

#include <Commands/Subsystem.h>
#include <CanTalon.h>

class Climber : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	CANTalon *climberMotor;

public:
	Climber();
	void InitDefaultCommand();
	void climb();
	void descend();
	void stop();
	void go(float);
};

#endif  // Climber_H
