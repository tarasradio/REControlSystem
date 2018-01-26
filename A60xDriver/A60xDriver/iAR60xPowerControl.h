#pragma once
#include "Elements/PowerSettingsStructure.h"
#include "Elements/PowerStatusStructure.h"

class iAR60xPowerControl
{
public:
	iAR60xPowerControl();
	virtual ~iAR60xPowerControl();

	virtual void setPowers(PowerSettingsStructure powers) = 0;
	virtual void getPowers(PowerStatusStructure &powers) = 0;
};

