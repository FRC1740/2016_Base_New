#include "WPILib.h"
#include "CommandBase.h"
#include "Commands/Command.h"
#include "Commands/autoNothing.h"
#include "Commands/autoGroupBaseline.h"
#include "Commands/autoGroupShootRed.h"
#include "Commands/autoGroupShootBlue.h"
#include "Commands/autoMove.h"
#include "Commands/autoMoveDistance.h"
#include "Commands/autoSkate.h"
#include "Commands/autoGroupGear.h"
#include "Commands/StandardTankDrive.h"
#include "Commands/MecanumTankDrive.h"
#include "Commands/ThreeAxisDrive.h"
#include "Commands/XBoxDrive.h"
#include "Commands/XBoxSaucer.h"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

// CRE 03-25-17 Experimental Vision Processing
//#include "vision/VisionPipeline.h"
//#include "vision/VisionRunner.h"

// #include "ADIS16448_IMU.h"

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
	// IMU Really needs to be part of the drivetrain subsystem
	double gyroAngle;
	char gyroString[64] = "";
	double shooterSpeed;
	char shooterSpeedString[64] = "";

	// Experimental Vision Tracking from ScreenStepsLive example
	// Use a separate thread so we don't choke the Robot thread
    static void VisionThread()
    {
        cs::UsbCamera camera = CameraServer::GetInstance()->StartAutomaticCapture();
        camera.SetResolution(640, 480);
        cs::CvSink cvSink = CameraServer::GetInstance()->GetVideo();
        cs::CvSource outputStreamStd = CameraServer::GetInstance()->PutVideo("Gray", 640, 480);
        cv::Mat source;
        cv::Mat output;
        while(true) {
            cvSink.GrabFrame(source);
            if (!source.empty()) {
            	cvtColor(source, output, cv::COLOR_BGR2GRAY);
            }
            else {
            	cvSink.GrabFrame(output);
            }
            outputStreamStd.PutFrame(output);
        }
    }

	virtual void RobotInit()
	{
		// The following two lines from the screensteps live example cause the code to crash.
		// std::thread visionThread(VisionThread);
		// visionThread.detach();

		CommandBase::init();
		shooterSpeed = 0.0;
//		SmartDashboard::init(); // i guess we init the smart dash here.... idk where else to do it, idk if its necessary

		drivemodechooser = new SendableChooser<Command*>;
//		drivemodechooser->AddObject("Standard Tank Drive", new StandardTankDrive());
//		drivemodechooser->AddObject("2 Joystick Mecanum", new MecanumTankDrive());
		drivemodechooser->AddDefault("Xbox Standard", new XBoxDrive());
		drivemodechooser->AddObject("3 Axis Joystick", new ThreeAxisDrive());
		drivemodechooser->AddObject("Xbox Saucer", new XBoxSaucer());
		SmartDashboard::PutData("Drive Mode", drivemodechooser);

		autonomouschooser = new SendableChooser<Command *>;
		autonomouschooser->AddDefault("Do Nothing", new autoNothing(15));
		autonomouschooser->AddObject("Baseline", new autoGroupBaseline());
		autonomouschooser->AddObject("Left Gear", new autoGroupGear(LEFTGEAR));
		autonomouschooser->AddObject("Center Gear", new autoMove(0, .4, 1.6));
		autonomouschooser->AddObject("Right Gear", new autoGroupGear(RIGHTGEAR));
		autonomouschooser->AddObject("Shoot", new autoGroupShootRed());
		SmartDashboard::PutData("Autonomous", autonomouschooser);

		// Uncomment this if we are using pneumatics
		cs::UsbCamera fwdCam = CameraServer::GetInstance()->StartAutomaticCapture();
		// It is possible to use two cameras, but bandwidth is an issue.
//		cs::UsbCamera revCam = CameraServer::GetInstance()->StartAutomaticCapture(1);
		//		compressor = new Compressor();
//		compressor->Start();

	}
	
	virtual void AutonomousInit()
	{
		autonomousCommand = (Command *) autonomouschooser->GetSelected();
		autonomousCommand->Start();
	}

	virtual void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run(); // FIXME: What does this do?
	}

	virtual void TeleopInit()
	{
		teleopcommand = (Command *) drivemodechooser->GetSelected();
		teleopcommand->Start();
	}

	virtual void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
		// gyroAngle = imu->GetAngleZ()/4.0;
		// sprintf(gyroString, "%5.2f degrees", gyroAngle);
		// SmartDashboard::PutString("Gyro Angle: ", gyroString);
	}

	virtual void TestInit()
	{
		lw = LiveWindow::GetInstance();
	}

	virtual void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(CommandBasedRobot);
