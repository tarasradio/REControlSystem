#pragma once

#include "Elements/SettingsStructure.h"

#include "iAR60xMoveControl.h"
#include "iAR60xPowerControl.h"
#include "iAR60xMotorsControl.h"
#include "iAR60xStatusInformation.h"

class iAR60xDriver 
	: iAR60xMoveControl, iAR60xMotorsControl, iAR60xPowerControl, iAR60xStatusInformation
{
public:
	iAR60xDriver();
	virtual ~iAR60xDriver();

	virtual void setSettings(SettingsStructure settings) = 0;
	virtual void getSettings(SettingsStructure &settings) = 0;

};

