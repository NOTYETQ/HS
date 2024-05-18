#ifndef LOCATIONS_H
#define LOCATIONS_H

#include "entity.h"

class Locations
{
public:
    Locations();
    ~Location();
    void setLocation_ID(int location_id);
    void setRegion(const QString &region);
    void setLocation(const QString &location);

    int getLocation_ID() const;
    QString getRegion() const;
    QString getLocation() const;
private:
    int Location_ID;
    QString Region;
    QString Location;
};

#endif // LOCATIONS_H
