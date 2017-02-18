#include "WPILib.h"
#include "Commands/autoNothing.h"
#include "Commands/Command.h"
#include "Commands/StandardTankDrive.h"
#include "Commands/MecanumTankDrive.h"
#include "Commands/ThreeAxisDrive.h"
#include "Commands/XBoxDrive.h"
#include "Commands/XBoxSaucer.h"
#include "CommandBase.h"
#include <CANTalon.h>
#include <Commands/autoGroupBaseline.h>
#include <Commands/autoGroupShoot.h>
#include <Commands/autoMove.h>
#include "ADIS16448_IMU.h"

/*
 *	Team 1740
 *	2017 Code
 *	Programming Staff:
 *
 *	Trevor "TLB is better than BLT" Bacon...
 *	New Mentor Sire Henry Crain: Majordomo of Programming and Python / C++ master
 *	Our Lord, Charles Estabrooks: Programming God and C / C++ savior
 *
 */

class CommandBasedRobot : public IterativeRobot {
private:
	// TODO can i initialize a pointer to datalogger here?
	Command *autonomousCommand;
	Command *teleopcommand;
	// LiveWindow uses the SmartDashboard in Test mode
	// All subsystems are automatically added to the LiveWindow
	LiveWindow *lw;
	Compressor *compressor;
	SendableChooser<Command*> *drivemodechooser;
	SendableChooser<Command*> *autonomouschooser;
	double gyroAngle;
	ADIS16448_IMU *imu = new ADIS16448_IMU;
	char gyroString[64] = "";
	double shooterSpeed;
	char shooterSpeedString[64] = "";

	virtual void RobotInit()
	{
//		logger->Log("RobotInit()", STATUS_MESSAGE);
		CommandBase::init();
		imu->Reset();
		gyroAngle = 0.0;
		shooterSpeed = 0.0;
//		SmartDashboard::init(); // i guess we init the smart dash here.... idk where else to do it, idk if its necessary

		drivemodechooser = new SendableChooser<Command*>;
//		drivemodechooser->AddObject("Standard Tank Drive", new StandardTankDrive());
//		drivemodechooser->AddObject("2 Joystick Mecanum", new MecanumTankDrive());
		drivemodechooser->AddDefault("Xbox Standard", new XBoxDrive());
		drivemodechooser->AddObject("3 Axis Joystick", new ThreeAxisDrive());
		// NOT USING // drivemodechooser->AddObject("Xbox Saucer", new XBoxSaucer());
		SmartDashboard::PutData("Drive Mode", drivemodechooser);

//		->Log("added objects", VERBOSE_MESSAGE);
		autonomouschooser = new SendableChooser<Command*>;
		autonomouschooser->AddDefault("Do Nothing", new autoNothing(15));
		autonomouschooser->AddObject("Baseline", new autoGroupBaseline());
		autonomouschooser->AddObject("Gear", new autoNothing(15));
		autonomouschooser->AddObject("Shoot", new autoGroupShoot());
		autonomouschooser->AddObject("Shoot+Baseline", new autoNothing(115));
		SmartDashboard::PutData("Autonomous", autonomouschooser);

		lw = LiveWindow::GetInstance();
		cs::UsbCamera fwdCam = CameraServer::GetInstance()->StartAutomaticCapture(0);
		// It is possible to use two cameras, but bandwidth is an issue.
//		cs::UsbCamera revCam = CameraServer::GetInstance()->StartAutomaticCapture(1);

		// Uncomment this if we are using pneumatics
//		compressor = new Compressor();
	}
	
	virtual void AutonomousInit()
	{
//		->Log("AutonomousInit()",STATUS_MESSAGE);
//		->Log("Starting Compressor", STATUS_MESSAGE);
//		compressor->Start();
		autonomousCommand = (Command *) autonomouschooser->GetSelected();
		Wait(1.0);
		autonomousCommand->Start();
		gyroAngle = imu->GetAngleZ()/4.0;
		sprintf(gyroString, "%5.2f degrees", gyroAngle);
		SmartDashboard::PutString("Gyro Angle: ", gyroString);
	}

	virtual void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run(); // FIXME: What does this do?
		gyroAngle = imu->GetAngleZ()/4.0;
		sprintf(gyroString, "%5.2f degrees", gyroAngle);
		SmartDashboard::PutString("Gyro Angle: ", gyroString);
	}

	virtual void TeleopInit()
	{
		teleopcommand = (Command *) drivemodechooser->GetSelected();
		teleopcommand->Start();

	}

	virtual void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
		gyroAngle = imu->GetAngleZ()/4.0;
		sprintf(gyroString, "%5.2f degrees", gyroAngle);
		SmartDashboard::PutString("Gyro Angle: ", gyroString);
	}

	virtual void TestInit()
	{

	}

	virtual void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(CommandBasedRobot);
