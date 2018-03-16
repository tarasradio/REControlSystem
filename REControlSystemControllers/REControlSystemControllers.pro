#-------------------------------------------------
#
# Project created by QtCreator 2018-03-17T02:27:32
#
#-------------------------------------------------

QT       -= gui

TARGET = REControlSystemControllers
TEMPLATE = lib
CONFIG += staticlib

SOURCES += REControlSystemControllers.cpp \
    PowerSupplyController.cpp \
    RealTimeController.cpp \
    PlayFileController.cpp \
    ManualController.cpp \
    RemoteConsoleController.cpp \
    ControllersManager.cpp \
    Controllers/ManualController.cpp \
    Controllers/PlayFileController.cpp \
    Controllers/PowerSupplyController.cpp \
    Controllers/RealTimeController.cpp \
    Controllers/RemoteConsoleController.cpp

HEADERS += REControlSystemControllers.h \
    PowerSupplyController.h \
    RealTimeController.h \
    PlayFileController.h \
    ManualController.h \
    RemoteConsoleController.h \
    ControllersManager.h \
    Controllers/ManualController.h \
    Controllers/PlayFileController.h \
    Controllers/PowerSupplyController.h \
    Controllers/RealTimeController.h \
    Controllers/RemoteConsoleController.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
