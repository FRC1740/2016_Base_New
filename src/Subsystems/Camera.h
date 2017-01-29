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
	void showGear();
	void showShooter();
	void showClimber();
	void Center();
};

#endif  // Camera_H
