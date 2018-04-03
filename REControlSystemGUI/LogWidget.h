#ifndef LOGWIDGET_H
#define LOGWIDGET_H

#include <QWidget>
#include <QTime>
#include <QTimer>

#include <string>
#include <vector>

#include "../REControlSystemInterfaces/ILogger.h"

namespace Ui {
class LogWidget;
}

class LogWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LogWidget(QWidget *parent = 0);
    ~LogWidget();

    void setLogger(ILogger * _logger);

    void addMessage(QString message);
    void startWrite();

private slots:
    void OnTimerTick();

private:
    //private variable
    Ui::LogWidget *ui;
    QTimer *_timer;
    int _time;
    int _interval;

    //private methods
    void updateData();

    ILogger *_logger;

};

#endif // LOGWIDGET_H
