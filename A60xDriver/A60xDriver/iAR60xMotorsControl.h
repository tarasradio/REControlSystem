#pragma once
#include "MotorStructure.h"

class iAR60xMotorsControl
{
public:
	iAR60xMotorsControl();
	virtual ~iAR60xMotorsControl();

	virtual void setMotors(MotorStructure motors[]) = 0;
	virtual void getMotors(MotorStructure motors[]) = 0;
};

