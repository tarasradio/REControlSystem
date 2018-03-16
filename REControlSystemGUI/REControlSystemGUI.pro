#-------------------------------------------------
#
# Project created by QtCreator 2018-03-04T01:40:54
#
#-------------------------------------------------

QT += gui
QT += network
QT += core
QT += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = REControlSystemGUI
TEMPLATE = app
CONFIG += qt c++14 thread

SOURCES += main.cpp\
        mainwindow.cpp \
    Logger.cpp \
    ControlWidgets/PowerSupplyControlWidget.cpp

HEADERS  += mainwindow.h \
    Logger.h \
    ControlWidgets/PowerSupplyControlWidget.h

FORMS    += mainwindow.ui \
    ControlWidgets/PowerSupplyControlWidget.ui

win32:
{
    LIBS += -L../../build_REControlSystem/build_AR60xHWDriver/debug/ -lAR60xHWDriver
    INCLUDEPATH += ../AR60xHWDriver/
}

unix:
{
    LIBS += -L../build/build_AR60xHWDriver/ -lAR60xHWDriver
    INCLUDEPATH += ../AR60xHWDriver/
}

RESOURCES += \
    icons/resicons.qrc
