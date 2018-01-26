#pragma once
#include "SensorStructure.h"

class iAR60xStatusInformation
{
public:
	iAR60xStatusInformation();
	~iAR60xStatusInformation();

	virtual void getSensorData(SensorStructure sensor) = 0;
	virtual void getAngle(SensorStructure sensor) = 0;
};

