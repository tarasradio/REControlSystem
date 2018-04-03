#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../AR60xHWDriver/AR60xHWDriver.h"
#include "../REControlSystemInterfaces/ILogger.h"
#include "Logger.h"

#include "ControlWidgets/PowerSupplyControlWidget.h"
#include "ControlWidgets/JointControlWidget.h"
#include "LogWidget.h"

#include "REControlSystemControllers/Controllers/PowerSupplyController.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

private:
    Ui::MainWindow *ui;
    Logger *_logger;
    AR60xHWDriver *driver;
    PowerSupplyControlWidget *_powerSupplyCW;
    PowerSupplyController *_powerController;

    LogWidget * _logWidget;

    JointControlWidget * _jointCW;

    void initWidgets();
};

#endif // MAINWINDOW_H
