#ifndef POWERSUPPLYCONTROLLER_H
#define POWERSUPPLYCONTROLLER_H

#include "REControlSystemInterfaces/IController.h"
#include "REControlSystemInterfaces/IPowerSupplyController.h"
#include "AR60xHWDriver/AR60xHWDriver.h"

class PowerSupplyController : public IPowerSupplyController, IController
{
public:
    PowerSupplyController();
    PowerState getPowerState() override;
    void setDriver(AR60xHWDriver * driver);
private:
    AR60xHWDriver *_driver;
};

#endif // POWERSUPPLYCONTROLLER_H
