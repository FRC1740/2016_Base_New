#include "pidGyroDrive.h"

#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SmartDashboard.h>
#include "WPILib.h"
#include "../RobotMap.h"

pidGyroDrive::pidGyroDrive() : PIDSubsystem("pidGyroDrive", 1.0, 0.0, 0.0)
{
	// Use these to get going:
	// SetSetpoint() -  Sets where the PID controller should move the system
	//                  to
	// Enable() - Enables the PID controller.
	// FIXME - CRE - I want to do something like this: rangeBoiler = parent->GetInstance()->rangeBoiler;

	front_left_motor = new CANTalon(FRONT_LEFT_MOTOR_ID);
	rear_left_motor = new CANTalon(REAR_LEFT_MOTOR_ID);
	front_right_motor = new CANTalon(FRONT_RIGHT_MOTOR_ID);
	rear_right_motor = new CANTalon(REAR_RIGHT_MOTOR_ID);

	front_left_motor->SetSafetyEnabled(false);
	rear_left_motor->SetSafetyEnabled(false);
	front_right_motor->SetSafetyEnabled(false);
	rear_right_motor->SetSafetyEnabled(false);

	/*
	front_left_motor->SetExpiration(.1);
	rear_left_motor->SetExpiration(.1);
	front_right_motor->SetExpiration(.1);
	rear_right_motor->SetExpiration(.1);
	*/

	imu = new ADIS16448_IMU;
	autobot = new RobotDrive(front_left_motor, rear_left_motor, front_right_motor, rear_right_motor);
	imu->Reset();

}

void pidGyroDrive::autoMove(double speed)
{
	double angle = imu->GetAngleZ()/4.0;
	printf("imu angle: %f\n", angle);
	autobot->Drive(speed, angle);
}

void pidGyroDrive::stop()
{
	autobot->StopMotor();
}
double pidGyroDrive::ReturnPIDInput()
{
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
	// return(rangeBoiler->getRangeInches());
	return 0.0;
}

void pidGyroDrive::UsePIDOutput(double output)
{
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
}

void pidGyroDrive::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}
