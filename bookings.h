#ifndef BOOKINGS_H
#define BOOKINGS_H

#include "entity.h"
#include <QDateTime>

class Bookings : public Entity {
public:
    Bookings();
    ~Bookings();

    void setBooking_ID(int booking_id);
    void setHurricane(const QString &hurricane);
    void setUserSSN(const QString &userssn);
    void setStatus(const QString &status);
    void setShelter(const QString &shelter);
    void setBooking_Date_Time(QDateTime booking_date_time);


    int getBooking_ID() const;
    QString getHurricane() const;
    QString getUserSSN() const;
    QString getStatus() const;
    QString getShelter() const;
    QDateTime getBooking_Date_Time() const;

private:
    int Booking_ID;
    QString Hurricane;
    QString UserSSN;
    QString Status;
    QString Shelter;
    QDateTime Booking_Date_Time;
};

#endif // BOOKINGS_H
