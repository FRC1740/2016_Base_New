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
#define FRONT_LEFT_MOTOR_ID 3
#define FRONT_RIGHT_MOTOR_ID 4
#define REAR_LEFT_MOTOR_ID 1
#define REAR_RIGHT_MOTOR_ID 2

// Other motors specific to each year's challenge
#define CLIMBER_MOTOR_ID 5

// Shooter Subsystem
#define SHOOTER_MOTOR_ID 6
#define SHOOTER_COUNTER_DIO_PORT 0
#define GATE_MOTOR_ID 7


// 2017 - Using new IMU instead of analog gyro
// Drivetrain Gyro for Steering Correction
// #define ANALOG_GYRO_PORT 0

// TODO VECTORIZE JOYSTICK INPUTS

// CRE 2017-02-04: Analog Port 0 on the RoboRio is Number 1 in the C++ Library. Go figure...
#define ROBORIO_ANALOG_ZERO 1
#define ROBORIO_ANALOG_ONE 2
#define ROBORIO_ANALOG_TWO 3
#define ROBORIO_ANALOG_THREE 4

// Rangefinder Subsystem
#define BOILER_RANGE_LIGHT_RELAY_PORT 0
#define GEAR_LIGHT_RELAY_PORT 1
#define DOOR_SOLENOID_RELAY_PORT 2

// DIO Ports for Ultrasonic Rangefinder
#define BOILER_RANGE_OUTPUT_PORT 8
#define BOILER_RANGE_INPUT_PORT 9

// Pneumatic port configuration
#define CYLINDER_PORT0 0 // Gripper solenoid wired to port 0 on pneumatic break-out card
#define CYLINDER_PORT1 1 // Release solenoid wired to port 1 on pneumatic break-out card

#endif
