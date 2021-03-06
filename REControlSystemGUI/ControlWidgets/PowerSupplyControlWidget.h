#ifndef POWERSUPPLYCONTROLWIDGET_H
#define POWERSUPPLYCONTROLWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QIcon>
#include <QTimer>
#include "../../AR60xHWDriver/DataTypes/PowerState.h"
#include "REControlSystemInterfaces/IPowerSupplyController.h"

namespace Ui {
class PowerSupplyControlWidget;
}

class PowerSupplyControlWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PowerSupplyControlWidget(QWidget *parent = 0);
    ~PowerSupplyControlWidget();

    void setController(IPowerSupplyController *controller);

    void updateInfo(PowerState state);

private slots:
    void onSupplyButtonsClicked();
    //void onSupply48VChanged(bool checked);
    //void onSupply8V2Changed(bool checked);
    //void onSupply8V1Changed(bool checked);
    //void onSupply6V2Changed(bool checked);
    //void onSupply6V1Changed(bool checked);

    //void onAllSuppliesChanged(bool checked);
    //void onRebootPower();
    //void stepRebootPower();

    void OnTimerTick();

private:
    Ui::PowerSupplyControlWidget *ui;

    enum PowerStates
    {
        RebootPowerStart,
        RebootPowerDown,
        RebootPowerUp,
        NotReboot
    };

    enum SupplyButtons
    {
        button48V = 1,
        button8V2,
        button8V1,
        button6V2,
        button6V1,
        buttonAllSupplies
    };

    IPowerSupplyController *_controller;

    void initGrid();

    QTimer *_timer;
    int _time;
    int _interval;
};

#endif // POWERSUPPLYCONTROLWIDGET_H
