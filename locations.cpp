#include "locations.h"

Locations::Locations() {}
Locations::~Locations() {}

void Locations::setLocation_ID(int location_id){
    Location_ID = location_id;
}
void Locations::setRegion(const QString &region){
    Region = region;
}
void Locations::setLocation(const QString &location){
    Location = location;
}

int Locations::getLocation_ID() const{
    return Location_ID;
}
QString Locations::getRegion() const{
    return Region;
}
QStringLocations::getLocation() const{
    return Location;
}