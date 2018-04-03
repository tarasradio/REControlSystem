#ifndef JOINTCONTROLWIDGET_H
#define JOINTCONTROLWIDGET_H

#include <QWidget>

namespace Ui {
class JointControlWidget;
}

class JointControlWidget : public QWidget
{
    Q_OBJECT
public:
    //public methods
    explicit JointControlWidget(QWidget *parent = 0);
    ~JointControlWidget();
    //void setModel(MotorTableModel *model);
    void UpdateData();

    //void setMover(Mover * mover){ m_mover = mover; }

signals:
    //void PropertyChanged(int Number);

public slots:
    //void RowChanged(int cRow);

private slots:
    void on_ButtonSTOP_clicked();
    void on_ButtonBRAKE_clicked();
    void on_ButtonRELAX_clicked();

    void on_groupBoxCalibration_clicked(bool checked);
    void on_ButtonSaveZero_clicked();

    void on_checkBoxTrace_clicked(bool checked);
    void on_SliderAngle_sliderMoved(int position);

    void SliderInit();

private:
    //private variable
    enum States {TRACE, STOP, STOPBRAKE, RELAX, CALIBRATE};
    States state;

    Ui::JointControlWidget *ui;
    //MotorTableModel * mModel;

    int currentRow;
    int CurrentNumber;
    bool Reverce;
    int ReverceCoeff;

    //private methods
    void initWidgets();
    void updateInfo();
};

#endif // JOINTCONTROLWIDGET_H
