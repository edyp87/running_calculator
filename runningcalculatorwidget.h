#ifndef RUNNINGCALCULATORWIDGET_H
#define RUNNINGCALCULATORWIDGET_H

#include <QMainWindow>

namespace Ui {
class RunningCalculatorWidget;
}

class RunningCalculatorWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit RunningCalculatorWidget(QWidget *parent = 0);
    ~RunningCalculatorWidget();

public slots:
    void changedSpeed(const QString & text);
    void changedPace(const QString & text);
    void calculatePressed();

private:
    QString createSpeedLabel(double computedPace);
    QString createPaceLabel(double computedSpeed);
    QString createTimeToFinishLabel(double computedTime);
    Ui::RunningCalculatorWidget *ui;
};

#endif // RUNNINGCALCULATORWIDGET_H
