#ifndef POWERSUPPLYCONTROLLER_H
#define POWERSUPPLYCONTROLLER_H

#include "REControlSystemInterfaces/IController.h"
#include "REControlSystemInterfaces/IPowerSupplyController.h"

class PowerSupplyController : public IPowerSupplyController, IController
{
public:
    PowerSupplyController();
    PowerState getPowerState() override;
};

#endif // POWERSUPPLYCONTROLLER_H
