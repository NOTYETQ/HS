#include "bookings.h"

Bookings::Bookings() {

}
Bookings::~Bookings(){

}


void Bookings::setBooking_ID(int booking_id){
    Booking_ID = booking_id;
}
void Bookings::setHurricane(const QString &hurricane){
    Hurricane = hurricane;
}
void Bookings::setUserSSN(const QString &userssn){
    UserSSN = userssn;
}
void Bookings::setStatus(const QString &status){
    Status = status;
}
void Bookings::setShelter(const QString &shelter){
    Shelter = shelter;
}
void Bookings::setBooking_Date_Time(QDateTime booking_date_time){
    Booking_Date_Time = booking_date_time;
}


int Bookings::getBooking_ID() const{
    return Booking_ID;
}
QString Bookings::getHurricane() const{
    return Hurricane;
}
QString Bookings::getUserSSN() const{
    return UserSSN;
}
QString Bookings::getStatus() const{
    return Status;
}
QString Bookings::getShelter() const{
    return Shelter;
}
QDateTime Bookings::getBooking_Date_Time() const{
    return Booking_Date_Time;
}
