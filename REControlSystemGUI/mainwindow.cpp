#include "MainWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _logger = new Logger();
    driver = new AR60xHWDriver(_logger);

    //driver->loadConfig("config_backup.xml");
    //driver->saveConfig("config_to.xml");

    bool isOk = driver->loadConfig("config_backup.xml");

    if(!isOk)
    {
        qDebug() << "load config file failed" << endl;
        exit(0);
    }
    else
    {
        qDebug() << "load config file success" << endl;
    }

    driver->initPackets();

    qDebug() << "init packets success" << endl;

    driver->robotConnect();
    driver->SupplySetState(PowerData::Supply12V, true);

    initWidgets();

    qDebug() << "joint 1 prepaired for trace" << endl;
}

MainWindow::~MainWindow()
{
    driver->robotDisconnect();
    qDebug() << "disconnected success" << endl;
    delete ui;
}

void MainWindow::initWidgets()
{
    _powerSupplyCW = new PowerSupplyControlWidget();
    ui->PowerControlLayout->addWidget(_powerSupplyCW);

    _powerController = new PowerSupplyController();
    _powerController->setDriver(driver);
    _powerSupplyCW->setController(_powerController);

    _jointCW = new JointControlWidget();
    ui->JointControlLayout->addWidget(_jointCW);

    _logWidget = new LogWidget();
    ui->LoggerLayout->addWidget(_logWidget);

    _logWidget->setLogger(_logger);
    _logWidget->startWrite();


}
