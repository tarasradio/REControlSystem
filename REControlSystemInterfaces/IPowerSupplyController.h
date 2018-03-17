#ifndef IPOWERSUPPLYCONTROLLER_H
#define IPOWERSUPPLYCONTROLLER_H

#include "../AR60xHWDriver/HardwareInterfaces/IAR60xPowerControl.h"
#include "../AR60xHWDriver/HardwareInterfaces/IAR60xPowerState.h"

class IPowerSupplyController
{
public:
    virtual PowerState getPowerState() = 0;
};

#endif // IPOWERSUPPLYCONTROLLER_H
