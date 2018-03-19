#include "PowerSupplyController.h"

PowerSupplyController::PowerSupplyController()
{
    suppliesState[PowerData::Supply48V] = false;
    suppliesState[PowerData::Supply12V] = false;
    suppliesState[PowerData::Supply8V1] = false;
    suppliesState[PowerData::Supply8V2] = false;
    suppliesState[PowerData::Supply6V1] = false;
    suppliesState[PowerData::Supply6V2] = false;
}

PowerState PowerSupplyController::getPowerState()
{
    PowerState state;
    state.power6V1State = _driver->PowerGetSupplyState(PowerData::Supply6V1);
    state.power6V2State = _driver->PowerGetSupplyState(PowerData::Supply6V2);
    state.power8V1State = _driver->PowerGetSupplyState(PowerData::Supply8V1);
    state.power8V2State = _driver->PowerGetSupplyState(PowerData::Supply8V2);
    state.power12VState = _driver->PowerGetSupplyState(PowerData::Supply12V);
    state.power48VState = _driver->PowerGetSupplyState(PowerData::Supply48V);
    return state;
}

void PowerSupplyController::setDriver(AR60xHWDriver *driver)
{
    this->_driver = driver;
}

void PowerSupplyController::setSupplyState(PowerData::PowerSupplies supply, bool onOff)
{
    _driver->SupplySetState(supply, onOff);
    suppliesState.at(supply) = onOff;
}

bool PowerSupplyController::getSupplyState(PowerData::PowerSupplies supply)
{
    return suppliesState.at(supply);
}
