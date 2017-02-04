#include "WPILib.h"
#include "Commands/BasicAuto.h"
#include "Commands/DoNothing.h"
#include "Commands/Command.h"
#include "Commands/Move.h"
#include "Commands/StandardTankDrive.h"
#include "Commands/MecanumTankDrive.h"
#include "Commands/ThreeAxisDrive.h"
#include "Commands/XBoxDrive.h"
#include "Commands/XBoxSaucer.h"
#include "CommandBase.h"

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
	ADIS16448_IMU *imu;

	virtual void RobotInit()
	{
//		logger->Log("RobotInit()", STATUS_MESSAGE);
		CommandBase::init();
//		SmartDashboard::init(); // i guess we init the smart dash here.... idk where else to do it, idk if its necessary

		drivemodechooser = new SendableChooser<Command*>;
//		drivemodechooser->AddObject("Standard Tank Drive", new StandardTankDrive());
//		drivemodechooser->AddObject("2 Joystick Mecanum", new MecanumTankDrive());
		drivemodechooser->AddDefault("Xbox Standard", new XBoxDrive());
		drivemodechooser->AddObject("3 Axis Joystick", new ThreeAxisDrive());
		drivemodechooser->AddObject("Xbox Experimental", new XBoxSaucer());
		SmartDashboard::PutData("Drive Mode", drivemodechooser);

//		->Log("added objects", VERBOSE_MESSAGE);
		autonomouschooser = new SendableChooser<Command*>;
		autonomouschooser->AddDefault("Do Nothing", new DoNothing(15));
		autonomouschooser->AddObject("MoveToBaseline", new BasicAuto());
//		autonomouschooser->AddObject("Testing move", new Move(270, .3, 5));
		SmartDashboard::PutData("Autonomous", autonomouschooser);

		lw = LiveWindow::GetInstance();
//		->Log("Starting robot!", VERBOSE_MESSAGE);
//		->Flush();
		cs::UsbCamera fwdCam = CameraServer::GetInstance()->StartAutomaticCapture(0);
		// It is possible to use two cameras, but bandwidth will be an issue.
//		cs::UsbCamera revCam = CameraServer::GetInstance()->StartAutomaticCapture(1);

		// Uncomment this if we are using pneumatics
//		compressor = new Compressor();

		// New Inertial Measurement Unit for 2017. Plugs directly into RoboRio. Woo hoo!
		imu = new ADIS16448_IMU;
	}
	
	virtual void AutonomousInit()
	{
//		->Log("AutonomousInit()",STATUS_MESSAGE);
//		->Log("Starting Compressor", STATUS_MESSAGE);
//		compressor->Start();
		autonomousCommand = (Command *) autonomouschooser->GetSelected();
		autonomousCommand->Start();
	}

	virtual void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	virtual void TeleopInit()
	{
//		->Log("Entering TeleopInit()", STATUS_MESSAGE);
//		autonomousCommand->Cancel();
		teleopcommand = (Command *) drivemodechooser->GetSelected();
		teleopcommand->Start();
//		->End();
	}

	virtual void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
		printf("imu->GetAngleZ: %f\n", imu->GetAngleZ());
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
