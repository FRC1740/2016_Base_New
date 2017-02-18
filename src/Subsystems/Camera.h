#ifndef Camera_H
#define Camera_H

#include <Commands/Subsystem.h>
#include "Servo.h"

class Camera : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Servo *Mount;
	double ServoAngle;

public:
	Camera();
	void InitDefaultCommand();
	void ShowGear();
	void ShowShooter();
	void ShowClimber();
	void Center();
	float GetPos(); // Returns camera mount/servo position
	bool CanTurnLeft();
	float TurnLeft();
	bool CanTurnRight();
	float TurnRight();
};

#endif  // Camera_H
