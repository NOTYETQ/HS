#include "bookingscrud.h"

BookingsCRUD::BookingsCRUD()
{

}
bool BookingsCRUD::add(const Entity& entity) override {
    const Bookings& booking = static_cast<const Bookings&>(entity);
    QString insertCommand = buildInsertCommand(booking);

    QSqlQuery query = m_database.prepare(insertCommand); // Assuming m_database is a member

    query.bindValue(":hurricane", booking.getHurricane()); // Bind values using getters
    query.bindValue(":userssn", booking.getUserSSN());
    query.bindValue(":status", booking.getStatus());
    query.bindValue(":shelter", booking.getShelter());

    try {
        query.exec();
        return true;
    } catch (const std::runtime_error& error) {
        qDebug() << "Error adding booking: " << error.what();
        return false;
    }
}
`bool BookingsCRUD::edit(const Entity& entity) {
    dynamic_cast<Bookings*>(&entity);

}
bool BookingsCRUD::delete_(const Entity& entity) {
    dynamic_cast<Bookings*>(&entity);

}
bool BookingsCRUD::view(const Entity& entity) {
                                              dynamic_cast<Bookings*>(&entity)

}

 QString getTableName() const{
    return "Bookings";
}
 QString buildInsertCommand(const Entity& entity) const{
     Bookings bookings = dynamic_cast<Bookings*>(&entity);

    QString query = "INSERT INTO Bookings (Hurricane, User, Status, Shelter, Booking_Date_Time) "
                    "SELECT "
                    "(SELECT Hurricane_ID FROM Hurricanes WHERE Name = :hurricane), "
                    "(Select User FROM Users WHERE UserSSN = :userssn)
                    "(SELECT Status_ID FROM Status WHERE Status = :status), "
                    "(SELECT Shelter_ID FROM Shelters WHERE Name = :shelter), "
                    "NOW();";

 }
 QString buildUpdateCommand(const Entity& entity) const{
     dynamic_cast<Bookings*>(&entity);
 }
 QString buildDeleteCommand(const Entity& entity) const{
     dynamic_cast<Bookings*>(&entity);
 }
 QString buildSelectCommand(const Entity& entity) const{
     dynamic_cast<Bookings*>(&entity);
 }
 QString buildViewTableCommand() const{
     dynamic_cast<Bookings*>(&entity);
 }
