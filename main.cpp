#include "mainwindow.h"

#include <QApplication>
#include <bookings.h>
#include <bookingscrud.h>
#include <databasemanager.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    DatabaseManager db;
    db.openDatabase();





    Bookings b;
    b.setHurricane("1");
    b.setShelter("1");
    b.setUserSSN("1");
    b.setStatus("1");



    BookingsCRUD bookingsCRUD;

    SheltersCRUD sheltersCRUD)



    try {
        if (bookingsCRUD.add(b)) {
            qDebug() << "Booking added successfully.";
        } else {
            qDebug() << "Error adding booking.";
        }
    } catch (const std::runtime_error& e) {
        qDebug() << "Database error: " << e.what();
    }
    Bookings b1;
    b1.setBooking_ID(1);

    
    if (bookingsCRUD.view(b1, b1)) {
        qDebug() << "Booking details:";
        qDebug() << "  Hurricane:  " << b1.getHurricane();
        qDebug() << "  User SSN:  " << b1.getUserSSN();
        qDebug() << "  Shelter:  " << b1.getShelter();
        qDebug() << "  Status:  " << b1.getStatus();
        qDebug() << "  Date:  " << b1.getBooking_Date_Time();
    } else {
        qDebug() << "Booking with ID " << b1.getBooking_ID() << " not found.";
    }


    Bookings b3;
    b3.setBooking_ID(7);
    b3.setHurricane("2");
    b3.setShelter("2");
    b3.setUserSSN("2");
    b3.setStatus("2");
    try {
        if (bookingsCRUD.edit(b3)) {
            qDebug() << "Booking edited successfully.";
        } else {
            qDebug() << "Error editing booking.";
        }
    } catch (const std::runtime_error& e) {
        qDebug() << "Database error: " << e.what();
    }
    try {
        if (bookingsCRUD.delete(b3)) {
            qDebug() << "Booking deleted successfully.";
        } else {
            qDebug() << "Error deleted booking.";
        }
    } catch (const std::runtime_error& e) {
        qDebug() << "Database error: " << e.what();
    }
    return a.exec();
    try {
        if (bookingsCRUD.edit(b1)) {
            qDebug() << "Booking edited successfully.";
        } else {
            qDebug() << "Error editing booking.";
        }
    } catch (const std::runtime_error& e) {
        qDebug() << "Database error: " << e.what();
    }
    return a.exec();
}
