#include "testunits.h"
#include "../units.h"

void TestUnits::testEmpty() {
    QVERIFY(true);
}

void TestUnits::speedIsZeroAfterCreation()
{
    Speed speed;
    QCOMPARE(speed.distanceInKm, 0.0);
    QCOMPARE(speed.timeInHours,  0.0);
}

void TestUnits::speedIsZeroWhenPaceIsZero()
{
    Pace  pace;
    Speed speed(pace);
    QCOMPARE(speed.toKmPerH(), 0.0);
}

void TestUnits::testToKmPerH()
{
    Speed speed1(12.0, 1.0);
    QCOMPARE(speed1.toKmPerH(), 12.0);
    Speed speed2(12.0, 2.5);
    QCOMPARE(speed2.toKmPerH(), 4.8);
}

void TestUnits::testConvertions()
{
    Speed speed(12.5, 1.0);
    Pace pace(speed);
    QCOMPARE(pace.toMinPerKm(), 4.48);

    Speed speed2(pace);
    QCOMPARE(speed2.toKmPerH(), 12.5);
}
