#ifndef Camera_H
#define Camera_H

#include <Commands/Subsystem.h>
#include "Servo.h"

class Camera : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Servo *Mount;
	double Angle;

public:
	Camera();
	void InitDefaultCommand();
	void Gear();
	void Shooter();
	void Center();
	void Lift();
};

#endif  // Camera_H
