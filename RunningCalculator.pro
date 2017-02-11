#-------------------------------------------------
#
# Project created by QtCreator 2017-02-05T21:31:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RunningCalculator
TEMPLATE = app
CONFIG += c++11
# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        runningcalculatorwidget.cpp \
    runningcalculator.cpp \
    UT/testunits.cpp

HEADERS  += runningcalculatorwidget.h \
    runningcalculator.h \
    units.h \
    UT/testunits.h

FORMS    += runningcalculatorwidget.ui

test {
    message(Test build)

    QT += testlib
    TARGET = qttest-example-test
    SOURCES -= main.cpp

    HEADERS += \
        UT/testmathparser.h

    SOURCES += \
        UT/main.cpp
} else {
    message(Normal build)
}
