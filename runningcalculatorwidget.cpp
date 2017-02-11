#include "runningcalculatorwidget.h"
#include "ui_runningcalculatorwidget.h"

RunningCalculatorWidget::RunningCalculatorWidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RunningCalculatorWidget)
{
    ui->setupUi(this);
}

RunningCalculatorWidget::~RunningCalculatorWidget()
{
    delete ui;
}
