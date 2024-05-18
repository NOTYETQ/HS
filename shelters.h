#ifndef SHELTERS_H
#define SHELTERS_H

#include "entity.h"

class Shelters
{
public:
    Shelters();
    ~Shelters();

    void setShelter_ID(int shelter_id);
    void setShelter(const QString & shelter);
    void setLocation(const QString & location);
    void setAddress(const QString & address);
    void setCondition(const QString & condition);
    void setLatitude(const QString & latitude);
    void setLongitude(const QString & longitude);
    void setCapacity(int capacity);
    void setRemainingCapacity(int remainingcapacity);

    int getShelter_ID() const;
    QString getShelter() const;
    QString getLocation() const;
    QString getAddress() const;
    QString getCondition() const;
    QString getLatitude() const;
    QString getLongitude() const;
    int getCapacity() const;
    int getRemainingCapacity() const;
private:
    int Shelter_ID;
    QString Shelter;
    QString Location;
    QString Address;
    QString Condition;
    QString Latitude;
    QString Longitude;
    int Capacity;
    int RemainingCapacity;
};

#endif // SHELTERS_H
