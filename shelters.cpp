#include "shelters.h"

Shelters::Shelters() {}

Shelters::~Shelters(){}

void Shelters::setShelter_ID(int shelter_id){
    Shelter_ID = shelter_id;
}
void Shelters::setShelter(const QString & shelter){
    Shelter = shelter;
}
void Shelters::setLocation(const QString & location){
    Location = location;
}
void Shelters::setAddress(const QString & address){
    Address = address;
}
void Shelters::setCondition(const QString & condition){
    Condition = condition;
}
void Shelters::setLatitude(const QString & latitude){
    Latitude = latitude;
}
void Shelters::setLongitude(const QString & longitude){
    Longitude = longitude;
}
void Shelters::setCapacity(int capacity){}
void Shelters::setRemainingCapacity(int remainingcapacity){
    RemainingCapacity = remainingcapacity;
}

int Shelters::getShelter_ID() const{
    return Shelter_ID;
}
QString Shelters::getShelter() const{
    return Shelter;
}
QString Shelters::getLocation() const{
    return Location;
}
QString Shelters::getAddress() const{
    return Address;
}
QString Shelters::getCondition() const{
    return Condition;
}
QString Shelters::getLatitude() const{
    return Latitude;
}
QString Shelters::getLongitude() const{
    return Longitude;
}
int Shelters::getCapacity() const{
    return Capacity;
}
int Shelters::getRemainingCapacity() const{
    return RemainingCapacity;
}
