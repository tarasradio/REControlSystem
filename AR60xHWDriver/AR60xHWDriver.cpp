#include "AR60xHWDriver.h"

AR60xHWDriver::AR60xHWDriver(ILogger *logger)
{
    this->_logger = logger;
    desc = new AR60xDescription();
    _logger->addMessage("AR600xHWDriver created", ILogger::Info);
}

bool AR60xHWDriver::loadConfig(std::string fileName)
{
    XMLSerializer serializer;
    return serializer.deserialize(fileName, desc, &connectionData);
}

void AR60xHWDriver::initPackets()
{
    sendpacket = new AR60xSendPacket(desc);
    recvPacket = new AR60xRecvPacket(desc);

    connection = new UDPConnection();

    connection->setRecvPacket(recvPacket);
    connection->setSendPacket(sendpacket);

    connection->initPackets();
}

void AR60xHWDriver::robotConnect()
{
    connection->connectToHost(connectionData.host,
                              connectionData.sendPort,
                              connectionData.recvPort,
                              connectionData.sendDelay);
}

void AR60xHWDriver::robotDisconnect()
{
    connection->breakConnection();
    connection->wait();
}

void AR60xHWDriver::JointSetSettings(int joint, JointData settings)
{
    desc->joints.at(joint) = settings;
}

void AR60xHWDriver::JointSetPosition(int joint, int position)
{
    sendpacket->jointSetPosition(joint, position);
}

void AR60xHWDriver::JointSetOffset(int joint, int offset)
{
    desc->joints.at(joint).offset = offset;
    sendpacket->jointSetOffset(joint, offset);
}

void AR60xHWDriver::JointSetReverce(int joint, bool isReverce)
{
    desc->joints.at(joint).isReverce = isReverce;
}

void AR60xHWDriver::JointSetPIDGains(int joint, JointData::PIDGains gains)
{
    sendpacket->jointSetPGain(joint, gains.proportional);
    sendpacket->jointSetIGain(joint, gains.integral);
    sendpacket->jointSetDGain(joint, gains.derivative);
}

void AR60xHWDriver::JointSetLimits(int joint, JointData::JointLimits limits)
{
    sendpacket->jointSetLowerLimit(joint, limits.lowerLimit);
    sendpacket->jointSetUpperLimit(joint, limits.upperLimit);
}

void AR60xHWDriver::JointSetEnable(int joint, bool isEnable)
{
    desc->joints.at(joint).isEnable = isEnable;
}

void AR60xHWDriver::JointSetState(int joint, JointState::JointStates state)
{
    sendpacket->jointSetState(joint, state);
}

JointData AR60xHWDriver::JointGetSettings(int joint)
{
    return desc->joints.at(joint);
}

int AR60xHWDriver::JointGetPosition(int joint)
{
    return recvPacket->jointGetPosition(joint);
}

//TODO: проверить!!!!
JointState AR60xHWDriver::JointGetState(int joint)
{
    //return recvPacket->jointGetState(joint);
}

bool AR60xHWDriver::JointGetReverce(int joint)
{
    return desc->joints.at(joint).isReverce;
}

PowerState::PowerSupplyState AR60xHWDriver::JointGetSupplyState(int joint)
{
    PowerState::PowerSupplyState state;
    state.Voltage = recvPacket->jointGetVoltage(joint);
    state.Current = recvPacket->jointGetCurrent(joint);
    return state;
}

//TODO: Удалить JointSettings перенсти вместо него JointInformation!!!!!
JointData::JointLimits AR60xHWDriver::JointGetLimits(int joint)
{
    return desc->joints.at(joint).limits;
}

bool AR60xHWDriver::JointGetEnable(int joint)
{
    return desc->joints.at(joint).isEnable;
}

JointData::PIDGains AR60xHWDriver::JointGetPIDGains(int joint)
{
    return desc->joints.at(joint).gains;
}

void AR60xHWDriver::PowerSetSettings(PowerData settings)
{

}

void AR60xHWDriver::SupplySetState(PowerData::PowerSupplies supply, bool onOffState)
{
    if(onOffState)
        sendpacket->supplySetOn(supply);
    else
        sendpacket->supplySetOff(supply);
}

bool AR60xHWDriver::PowerGetOnOff(PowerData::PowerSupplies supply)
{
    //TODO: нет метода в recvpacket
}

PowerState::PowerSupplyState AR60xHWDriver::PowerGetSupplyState(PowerData::PowerSupplies supply)
{
    PowerState::PowerSupplyState state;
    state.Voltage = recvPacket->supplyGetVoltage(supply);
    state.Current = recvPacket->supplyGetCurrent(supply);
    return state;
}

SensorState AR60xHWDriver::SensorGetState(int sensor)
{
    SensorState state;
    state.name = desc->sensors.at(sensor).name;
    state.sensorValue = recvPacket->sensorGetValue(sensor);
}

AR60xDescription *AR60xHWDriver::getRobotDesc()
{
    return desc;
}

bool AR60xHWDriver::saveConfig(std::string fileName)
{
    XMLSerializer serializer;
    return serializer.serialize(fileName, desc, &connectionData);
}
