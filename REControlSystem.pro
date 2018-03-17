#-------------------------------------------------
#
# Project created by QtCreator 2018-03-17T23:12:44
#
#-------------------------------------------------

QT += gui
QT += network
QT += core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = REControlSystem
TEMPLATE = app


SOURCES += main.cpp \
    AR60xHWDriver/DataTypes/ConnectionData.cpp \
    AR60xHWDriver/DataTypes/JointData.cpp \
    AR60xHWDriver/DataTypes/JointState.cpp \
    AR60xHWDriver/DataTypes/PowerData.cpp \
    AR60xHWDriver/DataTypes/PowerState.cpp \
    AR60xHWDriver/DataTypes/SensorData.cpp \
    AR60xHWDriver/DataTypes/SensorState.cpp \
    AR60xHWDriver/Libs/TinyXML2/tinyxml2.cpp \
    AR60xHWDriver/RobotDescription/AR60xDescription.cpp \
    AR60xHWDriver/RobotPackets/AR60xRecvPacket.cpp \
    AR60xHWDriver/RobotPackets/AR60xSendPacket.cpp \
    AR60xHWDriver/AR60xHWDriver.cpp \
    AR60xHWDriver/UDPConnection.cpp \
    AR60xHWDriver/XMLSerializer.cpp \
    REControlSystemControllers/Controllers/ManualController.cpp \
    REControlSystemControllers/Controllers/PlayFileController.cpp \
    REControlSystemControllers/Controllers/PowerSupplyController.cpp \
    REControlSystemControllers/Controllers/RealTimeController.cpp \
    REControlSystemControllers/Controllers/RemoteConsoleController.cpp \
    REControlSystemControllers/ControllersManager.cpp \
    REControlSystemGUI/ControlWidgets/PowerSupplyControlWidget.cpp \
    REControlSystemGUI/Logger.cpp \
    REControlSystemGUI/MainWindow.cpp

HEADERS  += \
    AR60xHWDriver/DataTypes/ConnectionData.h \
    AR60xHWDriver/DataTypes/JointData.h \
    AR60xHWDriver/DataTypes/JointState.h \
    AR60xHWDriver/DataTypes/PowerData.h \
    AR60xHWDriver/DataTypes/PowerState.h \
    AR60xHWDriver/DataTypes/SensorData.h \
    AR60xHWDriver/DataTypes/SensorState.h \
    AR60xHWDriver/HardwareInterfaces/IAR60xJointControl.h \
    AR60xHWDriver/HardwareInterfaces/IAR60xJointState.h \
    AR60xHWDriver/HardwareInterfaces/IAR60xPowerControl.h \
    AR60xHWDriver/HardwareInterfaces/IAR60xPowerState.h \
    AR60xHWDriver/HardwareInterfaces/IAR60xSensorState.h \
    AR60xHWDriver/Libs/TinyXML2/tinyxml2.h \
    AR60xHWDriver/RobotDescription/AR60xDescription.h \
    AR60xHWDriver/RobotPackets/AR60xPacketsDefinitions.h \
    AR60xHWDriver/RobotPackets/AR60xRecvPacket.h \
    AR60xHWDriver/RobotPackets/AR60xSendPacket.h \
    AR60xHWDriver/AR60xHWDriver.h \
    AR60xHWDriver/UDPConnection.h \
    AR60xHWDriver/XMLSerializer.h \
    REControlSystemControllers/Controllers/ManualController.h \
    REControlSystemControllers/Controllers/PlayFileController.h \
    REControlSystemControllers/Controllers/PowerSupplyController.h \
    REControlSystemControllers/Controllers/RealTimeController.h \
    REControlSystemControllers/Controllers/RemoteConsoleController.h \
    REControlSystemControllers/ControllersManager.h \
    REControlSystemGUI/ControlWidgets/PowerSupplyControlWidget.h \
    REControlSystemGUI/Logger.h \
    REControlSystemInterfaces/ILogger.h \
    REControlSystemGUI/MainWindow.h

FORMS    += \
    REControlSystemGUI/ControlWidgets/PowerSupplyControlWidget.ui \
    REControlSystemGUI/MainWindow.ui

RESOURCES += \
    Resurses.qrc
