#include "PowerSupplyControlWidget.h"
#include "ui_PowerSupplyControlWidget.h"

PowerSupplyControlWidget::PowerSupplyControlWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PowerSupplyControlWidget)
{
    ui->setupUi(this);

    initGrid();

    _timer = new QTimer(this);
    _interval = 100;
    _timer->setInterval(_interval);
    connect(_timer, SIGNAL(timeout()), this, SLOT( OnTimerTick() ));
    _timer->start();
}

PowerSupplyControlWidget::~PowerSupplyControlWidget()
{
    delete ui;
}

void PowerSupplyControlWidget::setController(IPowerSupplyController *controller)
{
    _controller = controller;
    updateInfo(_controller->getPowerState());
}

void PowerSupplyControlWidget::updateInfo(PowerState state)
{
//    QPushButton *button;
//    button = (QPushButton*)ui->tableWidget->cellWidget(button48V, 3);
//    button->setChecked(_controller->getSupplyState(PowerData::Supply48V));
//    button = (QPushButton*)ui->tableWidget->cellWidget(button8V2, 3);
//    button->setChecked(_controller->getSupplyState(PowerData::Supply8V2));
//    button = (QPushButton*)ui->tableWidget->cellWidget(button8V1, 3);
//    button->setChecked(_controller->getSupplyState(PowerData::Supply8V1));
//    button = (QPushButton*)ui->tableWidget->cellWidget(button6V2, 3);
//    button->setChecked(_controller->getSupplyState(PowerData::Supply6V2));
//    button = (QPushButton*)ui->tableWidget->cellWidget(button6V1, 3);
//    button->setChecked(_controller->getSupplyState(PowerData::Supply6V1));
//    delete button;

    ui->tableWidget->item(button48V, 1)->setText(QString::number( state.power48VState.Voltage, 'f', 2));
    ui->tableWidget->item(button8V2, 1)->setText(QString::number( state.power8V2State.Voltage, 'f', 2));
    ui->tableWidget->item(button8V1, 1)->setText(QString::number( state.power8V1State.Voltage, 'f', 2));
    ui->tableWidget->item(button6V2, 1)->setText(QString::number( state.power6V2State.Voltage, 'f', 2));
    ui->tableWidget->item(button6V1, 1)->setText(QString::number( state.power6V1State.Voltage, 'f', 2));

    ui->tableWidget->item(button48V, 2)->setText(QString::number( state.power48VState.Current, 'f', 2));
    ui->tableWidget->item(button8V2, 2)->setText(QString::number( state.power8V2State.Current, 'f', 2));
    ui->tableWidget->item(button8V1, 2)->setText(QString::number( state.power8V1State.Current, 'f', 2));
    ui->tableWidget->item(button6V2, 2)->setText(QString::number( state.power6V2State.Current, 'f', 2));
    ui->tableWidget->item(button6V1, 2)->setText(QString::number( state.power6V1State.Current, 'f', 2));
}

void PowerSupplyControlWidget::onSupplyButtonsClicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) return;
    QVariant var = button->property("row");

    if (!var.isValid()) return;

    bool isChecked = button->isChecked();
    switch (var.toInt()) {
    case 1:
        _controller->setSupplyState(PowerData::Supply48V, isChecked );
        break;
    case 2:
        _controller->setSupplyState(PowerData::Supply8V2, isChecked );
        break;
    case 3:
        _controller->setSupplyState(PowerData::Supply8V1, isChecked );
        break;
    case 4:
        _controller->setSupplyState(PowerData::Supply6V2, isChecked );
        break;
    case 5:
        _controller->setSupplyState(PowerData::Supply6V1, isChecked );
        break;
    case 6:
        //onAllPowerChanged( button->isChecked() );
        break;
    default:
        break;
    }
}

void PowerSupplyControlWidget::OnTimerTick()
{
    updateInfo(_controller->getPowerState());
}

/**
 * @brief PowerSupplyControlWidget::initGrid
 * Инициализация таблицы с кнопками и значениями источников питания
 */
void PowerSupplyControlWidget::initGrid()
{
    int rowsNumber = ui->tableWidget->rowCount();

//    // заполнение столбца кнопками
//    for (int row = 1; row < rowsNumber; ++row)
//    {
//        // создаем кнопку
//        QPushButton* button = new QPushButton();
//        button->setProperty("row", row);
//        button->setCheckable(true);
//        button->setIconSize(QSize(50, 18));
//        button->setFlat(true);

//        // привязываем иконки
//        QIcon my_icon;
//        my_icon.addFile(":/icons/button/iconOn", QSize(), QIcon::Normal, QIcon::On);
//        my_icon.addFile(":/icons/button/iconOff", QSize(), QIcon::Normal, QIcon::Off);
//        button->setIcon(my_icon);

//         // задаем стиль
//        button->setStyleSheet("QPushButton:checked { \
//                               background: white; \
//                               border: 0; \
//                               border-style: outset;}");
//        // соединяем со слотом
//        connect(button, SIGNAL(clicked()), SLOT(onSupplyButtonsClicked()));
//        ui->tableWidget->setCellWidget(row, buttonsColumn, button);
//    }

    ui->tableWidget->setColumnWidth(1, 80);
    ui->tableWidget->setColumnWidth(2, 70);

    // все строки высотой 21px
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row)
        ui->tableWidget->setRowHeight(row, 21);

    QTableWidgetItem *itemSupplyDesc = new QTableWidgetItem;
    itemSupplyDesc->setText("Источники");
    itemSupplyDesc->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(0, 0, itemSupplyDesc);

    QTableWidgetItem *itemVoltage = new QTableWidgetItem;
    itemVoltage->setText("Напряжение");
    itemVoltage->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(0, 1, itemVoltage);

    QTableWidgetItem *itemCurrent = new QTableWidgetItem;
    itemCurrent->setText("Ток");
    itemCurrent->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(0, 2, itemCurrent);

    // вставляем ячейки со значениями
    for (int row = 1; row < ui->tableWidget->rowCount(); ++row)
    {
        QTableWidgetItem *itemVoltage = new QTableWidgetItem;
        itemVoltage->setText("0.00");
        itemVoltage->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row,1,itemVoltage);

        QTableWidgetItem *itemCurrent = new QTableWidgetItem;
        itemCurrent->setText("0.00");
        itemCurrent->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->setItem(row,2,itemCurrent);
    }

    QTableWidgetItem *itemSupply12V = new QTableWidgetItem;
    itemSupply12V->setText("12 Вольт");
    itemSupply12V->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(1, 0, itemSupply12V);

    // добавление надписей слева
    QTableWidgetItem *itemSupply48V = new QTableWidgetItem;
    itemSupply48V->setText("48 Вольт");
    itemSupply48V->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(2, 0, itemSupply48V);

    QTableWidgetItem *itemSupply8V2 = new QTableWidgetItem;
    itemSupply8V2->setText("8 Вольт (2)");
    itemSupply8V2->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(3, 0, itemSupply8V2);

    QTableWidgetItem *itemSupply8V1 = new QTableWidgetItem;
    itemSupply8V1->setText("8 Вольт (1)");
    itemSupply8V1->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(4, 0, itemSupply8V1);

    QTableWidgetItem *itemSupply6V2 = new QTableWidgetItem;
    itemSupply6V2->setText("6 Вольт (2)");
    itemSupply6V2->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(5, 0, itemSupply6V2);

    QTableWidgetItem *itemSupply6V1 = new QTableWidgetItem;
    itemSupply6V1->setText("6 Вольт (1)");
    itemSupply6V1->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(6, 0, itemSupply6V1);
}
