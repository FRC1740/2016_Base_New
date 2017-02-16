#ifndef RangeFinder_H
#define RangeFinder_H

#include "WPILib.h"
#include "Commands/Subsystem.h"
#include "DataLogger.h"

// Calibrated based on measured distance
#define IN_FACTOR 1 / .00625
#define FT_FACTOR IN_FACTOR / 12

class RangeFinder: public Subsystem
{
private:
	Relay *light;
	AnalogInput *rangeBoiler;
	//	Ultrasonic *rangeBoiler;  // Digital RangeFinder Not Working

public:
	RangeFinder();
	void InitDefaultCommand();
	void Light(unsigned int);
	float GetAverageVoltage(void);
	float GetRangeInches(void);
};

#endif
