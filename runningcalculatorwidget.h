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

private:
    Ui::RunningCalculatorWidget *ui;
};

#endif // RUNNINGCALCULATORWIDGET_H
