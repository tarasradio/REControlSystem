#pragma once
#include "Elements/MotorSettingsStructure.h"

class iAR60xMotorsControl
{
public:
	iAR60xMotorsControl();
	virtual ~iAR60xMotorsControl();

	virtual void setMotors(MotorSettingsStructure motors[]) = 0;
	virtual void getMotors(MotorSettingsStructure motors[]) = 0;
};

