#ifndef UNITS_H
#define UNITS_H

struct Pace;

struct Speed
{
    explicit Speed(const Pace & pace)
    {
        distanceInKm = 0;
    }

    int distanceInKm = 0;
    int timeInHours = 0;
};

struct Pace
{
    int timeInKm = 0;
    int timeInMinutes = 0;
};

#endif // UNITS_H
