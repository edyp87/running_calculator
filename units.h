#ifndef UNITS_H
#define UNITS_H

#include <QDebug>

double convertSpeedToPace(double speed)
{
    if (speed == 0.0)
    {
        return 0.0;
    }
    else
    {
        double minutes = 60 / speed;
        int onlyMinutes = minutes;
        double secondsAsFraction = (60 * (minutes - onlyMinutes)) / 100;
        return onlyMinutes + secondsAsFraction;
    }
}

double convertPaceToSpeed(double pace)
{
    if (pace == 0.0)
    {
        return 0;
    }
    else
    {
        auto onlyMinutes = static_cast<int>(pace);
        double secondsAsFraction = (pace - onlyMinutes) * 100 / 60;
        return 60 / (onlyMinutes + secondsAsFraction);
    }
}

double convertSpeedAndDistanceToTime(double speed, double distance)
{
    if (speed == 0.0) return 0.0;
    auto time = distance / speed;
    qDebug() << QString::number(distance) + " " +QString::number( speed);
    qDebug() << time;
    int timeInt = time;
    double minutes = (time - timeInt) * 60 / 100;
    qDebug() << timeInt;
    qDebug() << minutes;
    return timeInt + minutes;
}

double convertPaceAndDistanceToTime(double pace, double distance)
{
    double speed = convertPaceToSpeed(pace);
    return convertSpeedAndDistanceToTime(speed, distance);
}

struct Pace;

struct Speed
{
    Speed() = default;
    explicit Speed(double km, double h = 1);
    explicit Speed(const Pace & pace);

    double toKmPerH() const;

    double distanceInKm = 0;
    double timeInHours = 1;
};

struct Pace
{
    Pace() = default;
    explicit Pace(double min, double km = 1);
    explicit Pace(const Speed & speed);

    double toMinPerKm() const;

    double distanceInKm = 0;
    double timeInMinutes = 1;
};

Speed::Speed(double km, double h) : distanceInKm(km), timeInHours(h) {}

Speed::Speed(const Pace &pace)
{
    if (pace.toMinPerKm() == 0.0)
    {
        distanceInKm = 0;
        timeInHours = 1;
    }
    else
    {
        int onlyMinutes = pace.toMinPerKm();
        double secondsAsFraction = (pace.toMinPerKm() - onlyMinutes) * 100 / 60;

        qDebug() << onlyMinutes;
        qDebug() << secondsAsFraction;
        distanceInKm = 60 / (onlyMinutes + secondsAsFraction);
        timeInHours = 1;
    }
}

double Speed::toKmPerH() const
{
    return distanceInKm / timeInHours;
}

Pace::Pace(double min, double km) : distanceInKm(km), timeInMinutes(min) {}

Pace::Pace(const Speed &speed)
{
    if (speed.toKmPerH() == 0.0)
    {
        timeInMinutes = 0;
        distanceInKm = 1;
    }
    else
    {
        double minutes = 60 / speed.toKmPerH();
        int onlyMinutes = minutes;
        double secondsAsFraction = (60 * (minutes - onlyMinutes)) / 100;
        timeInMinutes = onlyMinutes + secondsAsFraction;
        distanceInKm = 1;
    }
}

double Pace::toMinPerKm() const
{
    return timeInMinutes / distanceInKm;
}

#endif // UNITS_H
