#include "PowerSupplyController.h"

PowerSupplyController::PowerSupplyController()
{

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
