#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../AR60xHWDriver/AR60xHWDriver.h"
#include "../REControlSystemInterfaces/ILogger.h"
#include "Logger.h"

#include "ControlWidgets/PowerSupplyControlWidget.h"

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
    void on_pushButton_clicked();

    void on_ButtonOn_clicked();

    void on_horizontalSlider_sliderMoved(int position);

private:
    Ui::MainWindow *ui;
    Logger *_logger;
    AR60xHWDriver *driver;
    PowerSupplyControlWidget *_powerSupplyCW;
    PowerSupplyController *_powerController;

    void initWidgets();
};

#endif // MAINWINDOW_H
