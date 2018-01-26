#pragma once
#include "PowerInStructure.h"
#include "PowerOutStructure.h"

class iAR60xPowerControl
{
public:
	iAR60xPowerControl();
	virtual ~iAR60xPowerControl();

	virtual void setPowers(PowerInStructure powers[]) = 0;
	virtual void getPowers(PowerOutStructure powers[]) = 0;
};

