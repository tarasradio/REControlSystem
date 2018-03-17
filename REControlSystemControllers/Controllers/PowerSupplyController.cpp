#include "PowerSupplyController.h"

PowerSupplyController::PowerSupplyController()
{

}

PowerState PowerSupplyController::getPowerState()
{
    PowerState state;
    state.power6V1State.Voltage = 6.1;
    state.power6V2State.Voltage = 6.2;
    state.power8V1State.Voltage = 8.1;
    state.power8V1State.Voltage = 6.2;
    state.power48VState.Voltage = 48.0;
    return state;
}
