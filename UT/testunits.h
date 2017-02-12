#ifndef TESTUNITS_H
#define TESTUNITS_H

#include <QtTest>

class TestUnits : public QObject {
    Q_OBJECT

private slots:
    void testEmpty();
    void speedIsZeroAfterCreation();
    void speedIsZeroWhenPaceIsZero();
    void testToKmPerH();
    void testConvertions();
};

#endif // TESTUNITS_H
