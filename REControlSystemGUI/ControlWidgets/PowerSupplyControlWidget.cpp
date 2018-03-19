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
    ui->tableWidget->item(1,1)->setText(QString::number( state.power48VState.Voltage, 'f', 2));
    ui->tableWidget->item(2,1)->setText(QString::number( state.power8V2State.Voltage, 'f', 2));
    ui->tableWidget->item(3,1)->setText(QString::number( state.power8V1State.Voltage, 'f', 2));
    ui->tableWidget->item(4,1)->setText(QString::number( state.power6V2State.Voltage, 'f', 2));
    ui->tableWidget->item(5,1)->setText(QString::number( state.power6V1State.Voltage, 'f', 2));

    ui->tableWidget->item(1,2)->setText(QString::number( state.power48VState.Current, 'f', 2));
    ui->tableWidget->item(2,2)->setText(QString::number( state.power8V2State.Current, 'f', 2));
    ui->tableWidget->item(3,2)->setText(QString::number( state.power8V1State.Current, 'f', 2));
    ui->tableWidget->item(4,2)->setText(QString::number( state.power6V2State.Current, 'f', 2));
    ui->tableWidget->item(5,2)->setText(QString::number( state.power6V1State.Current, 'f', 2));
}

void PowerSupplyControlWidget::onSupplyButtonsClicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) return;
    QVariant var = button->property("row");

    if (!var.isValid()) return;
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
    int buttonsColumn = 3;
    int rowsNumber = ui->tableWidget->rowCount();

    // заполнение столбца кнопками
    for (int row = 1; row < rowsNumber; ++row)
    {
        // создаем кнопку
        QPushButton* button = new QPushButton();
        button->setProperty("row", row);
        button->setCheckable(true);
        button->setIconSize(QSize(50, 18));
        button->setFlat(true);

        // привязываем иконки
        QIcon my_icon;
        my_icon.addFile(":/icons/button/iconOn", QSize(), QIcon::Normal, QIcon::On);
        my_icon.addFile(":/icons/button/iconOff", QSize(), QIcon::Normal, QIcon::Off);
        button->setIcon(my_icon);

         // задаем стиль
        button->setStyleSheet("QPushButton:checked { \
                               background: white; \
                               border: 0; \
                               border-style: outset;}");
        // соединяем со слотом
        connect(button, SIGNAL(clicked()), SLOT(onSupplyButtonsClicked()));
        ui->tableWidget->setCellWidget(row, buttonsColumn, button);
    }

    ui->tableWidget->setColumnWidth(1, 50);
    ui->tableWidget->setColumnWidth(2, 50);
    ui->tableWidget->setColumnWidth(3, 50);

    // все строки высотой 21px
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row)
        ui->tableWidget->setRowHeight(row, 21);

    QTableWidgetItem *itemVoltage = new QTableWidgetItem;
    itemVoltage->setText("Voltage");
    itemVoltage->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(0, 1, itemVoltage);

    QTableWidgetItem *itemCurrent = new QTableWidgetItem;
    itemCurrent->setText("Current");
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

    // добавление надписей слева
    QTableWidgetItem *itemSupply48V = new QTableWidgetItem;
    itemSupply48V->setText("48V");
    itemSupply48V->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(1, 0, itemSupply48V);

    QTableWidgetItem *itemSupply8V2 = new QTableWidgetItem;
    itemSupply8V2->setText("8V (2)");
    itemSupply8V2->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(2, 0, itemSupply8V2);

    QTableWidgetItem *itemSupply8V1 = new QTableWidgetItem;
    itemSupply8V1->setText("8V (1)");
    itemSupply8V1->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(3, 0, itemSupply8V1);

    QTableWidgetItem *itemSupply6V2 = new QTableWidgetItem;
    itemSupply6V2->setText("6V (2)");
    itemSupply6V2->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(4, 0, itemSupply6V2);

    QTableWidgetItem *itemSupply6V1 = new QTableWidgetItem;
    itemSupply6V1->setText("6V (1)");
    itemSupply6V1->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(5, 0, itemSupply6V1);

    QTableWidgetItem *itemSuppliesAll = new QTableWidgetItem;
    itemSuppliesAll->setText("Все источники");
    itemSuppliesAll->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->setItem(6, 0, itemSuppliesAll);
}
