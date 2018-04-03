#include "LogWidget.h"
#include "ui_LogWidget.h"

LogWidget::LogWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogWidget)
{
    ui->setupUi(this);

    _timer = new QTimer(this);
    _interval = 10;
    _timer->setInterval(_interval);
    connect(_timer, SIGNAL(timeout()), this, SLOT(OnTimerTick()));
}

LogWidget::~LogWidget()
{
    delete ui;
}

void LogWidget::setLogger(ILogger *logger)
{
    this->_logger = logger;
}

void LogWidget::addMessage(QString message)
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString prefix = "<font color = 'brown'>" + currentDateTime.toString("dd.MM.yyyy HH:mm:ss") + "</font> - ";
    ui->textView->append(prefix + message);
}

void LogWidget::startWrite()
{
    _timer->start();
}

void LogWidget::OnTimerTick()
{
    updateData();
}

void LogWidget::updateData()
{
    //std::vector<std::string> data = LogMaster::Inst()->getLastStrings();
    //for(int i = 0; i < mData.size(); i++)
    //    addMessage(QString::fromStdString(mData.at(i)));
}
