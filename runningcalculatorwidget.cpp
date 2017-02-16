#include "runningcalculatorwidget.h"
#include "ui_runningcalculatorwidget.h"
#include "units.h"
#include <QDebug>

RunningCalculatorWidget::RunningCalculatorWidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RunningCalculatorWidget)
{
    ui->setupUi(this);
    QObject::connect(ui->speedEdit, &QLineEdit::textChanged,
                     this, &RunningCalculatorWidget::changedSpeed);
    QObject::connect(ui->paceEdit, &QLineEdit::textChanged,
                     this, &RunningCalculatorWidget::changedPace);
    QObject::connect(ui->calculateButton, &QPushButton::clicked,
                     this, &RunningCalculatorWidget::calculatePressed);
}

RunningCalculatorWidget::~RunningCalculatorWidget()
{
    delete ui;
}

void RunningCalculatorWidget::changedSpeed(const QString &text)
{
    double computedPace = convertSpeedToPace(text.toDouble());
    ui->computetPaceLabel->setText(createPaceLabel(computedPace));
}

void RunningCalculatorWidget::changedPace(const QString &text)
{
    double computedSpeed = convertPaceToSpeed(text.toDouble());
    ui->computedSpeedLabel->setText(createSpeedLabel(computedSpeed));
}

void RunningCalculatorWidget::calculatePressed()
{
    if (ui->tabWidget->currentIndex() == 0 && ui->speedEdit->text().size() != 0 &&
            ui->distanceLineEdit->text().size() != 0)
    {
        auto time = convertSpeedAndDistanceToTime(ui->speedEdit->text().toDouble(),
                                                  ui->distanceLineEdit->text().toDouble());
        ui->timeToFinishLabel->setText(createTimeToFinishLabel(time));
    }
    else if (ui->tabWidget->currentIndex() == 1 && ui->paceEdit->text().size() != 0 &&
             ui->distanceLineEdit->text().size() != 0)
    {
        auto time = convertPaceAndDistanceToTime(ui->paceEdit->text().toDouble(),
                                                  ui->distanceLineEdit->text().toDouble());
        ui->timeToFinishLabel->setText(createTimeToFinishLabel(time));
    }
}

QString RunningCalculatorWidget::createSpeedLabel(double computedPace)
{
    return "This is " + QString::number(computedPace) + " km / h";
}

QString RunningCalculatorWidget::createPaceLabel(double computedSpeed)
{
    return "This is " + QString::number(computedSpeed) + " min / km";
}

QString RunningCalculatorWidget::createTimeToFinishLabel(double computedTime)
{
    int hours = static_cast<int>(computedTime);
    int minutes = (computedTime - hours) * 100;
    return QString::number(hours) + " h : "
            + QString::number(minutes) + " min";
}


