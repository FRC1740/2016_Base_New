#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// Updated for 2017 Steamworks
// drivetrain motors go here, currently set up to assume 4 motor

// Use the following Talon ID for the Mecanum Drive Practice 'bot
#define FRONT_LEFT_MOTOR_ID 3
#define FRONT_RIGHT_MOTOR_ID 4
#define REAR_LEFT_MOTOR_ID 1
#define REAR_RIGHT_MOTOR_ID 2
#define CLIMBER_MOTOR_ID 5
#define SHOOTER_MOTOR_ID 6
#define AIM_MOTOR_ID 7

// Drivetrain Gyro for Steering Correction
#define DRIVE_GYRO_PORT 0

#define ANGLE_CORRECTION 5; // offsets straight by x degrees clockwise
// TODO VECTORIZE JOYSTICK INPUTS

// Rangefinder Subsystem
#define LIGHT_BAR_RELAY_PORT 0 // Compiler blows chunks if using relay port 0
#define BOILER_RANGE_INPUT_PORT 0  // Analog Ports
#define BOILER_RANGE_OUTPUT_PORT 1

// Pneumatic port configuration
#define CYLINDER_PORT0 0 // Gripper solenoid wired to port 0 on pneumatic break-out card
#define CYLINDER_PORT1 1 // Release solenoid wired to port 1 on pneumatic break-out card

#endif
