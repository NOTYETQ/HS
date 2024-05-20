#include "bookingscrud.h"

BookingsCRUD::BookingsCRUD()
{

}
BookingsCRUD::~BookingsCRUD(){

}
// ------------------------------------------------------------------------------------------------------------------------------------------------
// CRUD ADD FUNCTION
// Uses Values hurricaneid, userid, statusid, shelterid
// Accepts an object with these values already initialized
// Proper exception handling is left
// uses the buildInsertCommand()
// ------------------------------------------------------------------------------------------------------------------------------------------------
bool BookingsCRUD::add(const Entity& entity) {
    try {
        const Bookings* bookings = dynamic_cast<const Bookings*>(&entity);
        if (!bookings) {
            throw DatabaseException("Invalid Object");
        }
        QSqlQuery query;
        query.prepare(buildInsertCommand());
        query.bindValue(":hurricane_id", bookings->getHurricane());
        query.bindValue(":user_id", bookings->getUserSSN());
        query.bindValue(":status_id", bookings->getStatus());
        query.bindValue(":shelter_id", bookings->getShelter());

        if (!query.exec()) {
            throw std::runtime_error("something went wrong: " + query.lastError().text().toStdString());
        }

        qDebug("Success");
        return true;
    }
    catch (DatabaseException e) {
        throw e;
        return false;
    }
    catch (std::runtime_error e) {
        throw e;
        return false;
    }
    catch (std::exception e) {
        throw e ;
        return false;
    }

}

// ------------------------------------------------------------------------------------------------------------------------------------------------
// CRUD Edit FUNCTION
// Uses Values hurricaneid, userid, statusid, shelterid, bookingid
// Accepts an object with these values already initialized
// Proper exception handling is left
// uses the buildUpdateCommand()
// ------------------------------------------------------------------------------------------------------------------------------------------------
bool BookingsCRUD::edit(const Entity& entity) {
    try {
        const Bookings* bookings = dynamic_cast<const Bookings*>(&entity);
        if (!bookings) {
            throw DatabaseException("Invalid Object");
        }
        QSqlQuery query;
        query.prepare(buildUpdateCommand());
        query.bindValue(":booking_id", bookings->getBooking_ID());
        query.bindValue(":hurricane_id", bookings->getHurricane());
        query.bindValue(":user_id", bookings->getUserSSN());
        query.bindValue(":status_id", bookings->getStatus());
        query.bindValue(":shelter_id", bookings->getShelter());
        if (!query.exec()) {
            throw std::runtime_error("something went wrong: " + query.lastError().text().toStdString());
        }

        qDebug("Success");

        return true;

    }
    catch (DatabaseException e) {
        throw e;
        return false;
    }
    catch (std::runtime_error e) {
        throw e;
        return false;
    }
    catch (std::exception e) {
        throw e ;
        return false;
    }
}
// ------------------------------------------------------------------------------------------------------------------------------------------------
// CRUD Delete FUNCTION
// Uses Values bookingid
// Accepts an object with these values already initialized
// Proper exception handling is left
// uses the buildDeleteCommand()
// ------------------------------------------------------------------------------------------------------------------------------------------------
bool BookingsCRUD::delete_(const Entity& entity) {
    try {
        const Bookings* bookings = dynamic_cast<const Bookings*>(&entity);
        if (!bookings) {
            throw DatabaseException ("Invalid Object");
        }
        QSqlQuery query;
        query.prepare(buildDeleteCommand());
        query.bindValue(":booking_id", bookings->getBooking_ID());
        if (!query.exec()) {
            throw std::runtime_error("something went wrong: " + query.lastError().text().toStdString());
        }
        qDebug() << "Delete Sucess.";
        return true;
    }
    catch (DatabaseException e) {
        throw e;
        return false;
    }
    catch (std::runtime_error e) {
        throw e;
        return false;
    }
    catch (std::exception e) {
        throw e ;
        return false;
    }
}
// ------------------------------------------------------------------------------------------------------------------------------------------------
// CRUD View FUNCTION
// Uses Values bookingid
// Accepts an object with these values already initialized and a second object
// Writes whatever was received from the database into a second object, can use the same object
// Proper exception handling is left
// uses the buildViewCommand()
// ------------------------------------------------------------------------------------------------------------------------------------------------
bool BookingsCRUD::view(const Entity& entity, Entity& newentity) const {
    try {
        const Bookings* bookings = dynamic_cast<const Bookings*>(&entity);
        if (!bookings) {
            throw DatabaseException ("Invalid Object");
        }

        QSqlQuery query;
        query.prepare(buildSelectCommand());
        query.bindValue(":booking_id", bookings->getBooking_ID());

        if (!query.exec()) {
            throw std::runtime_error("something went wrong: " + query.lastError().text().toStdString());
        }
        qDebug("Query Success");

        if (!query.next()) {
            throw DatabaseException("Booking Not Found");
        }

        // Cast newentity to Bookings* (assuming it's valid) and populate using setters
        Bookings* mutableBooking = dynamic_cast<Bookings*>(&newentity);
        if (!mutableBooking) {
            throw DatabaseException ("Invalid Object");
        }

        mutableBooking->setHurricane(query.value("Hurricane").toString());
        mutableBooking->setUserSSN(query.value("SSN").toString());
        mutableBooking->setShelter(query.value("Shelter").toString());
        mutableBooking->setStatus(query.value("Status").toString());
        mutableBooking->setBooking_Date_Time(query.value("Booking_Date_Time").toString());
        mutableBooking->setBooking_ID(query.value("Booking_ID").toInt());
        return true;

    }
    catch (DatabaseException e) {
        throw e;
        return false;
    }
    catch (std::runtime_error e) {
        throw e;
        return false;
    }
    catch (std::exception e) {
        throw e ;
        return false;
    }

}

QString BookingsCRUD::getTableName() const{
    return "Bookings";
}

// ------------------------------------------------------------------------------------------------------------------------------------------------
// Build Commands
// The Queries used in the functions
// Uses the ids of the linking tables instead of the names due to potential conflicts
// ------------------------------------------------------------------------------------------------------------------------------------------------
QString BookingsCRUD::buildInsertCommand() const {
    return  "INSERT INTO Bookings "
                "(Hurricane, User, Status, Shelter, Booking_Date_Time) "
            "VALUES "
                "(:hurricane_id, :user_id, :status_id, :shelter_id, Now())";
}
QString BookingsCRUD::buildUpdateCommand() const {
    return  "UPDATE Bookings SET "
           "Hurricane = :hurricane_id, "
           "User = :user_id, "
           "Status = :status_id, "
           "Shelter = :shelter_id "
           "WHERE Booking_ID = :booking_id";
}

QString BookingsCRUD::buildDeleteCommand() const {
    return  "DELETE FROM Bookings "
           "WHERE Booking_ID = :booking_id";
}

QString BookingsCRUD::buildSelectCommand() const {
    return  "SELECT b.Booking_ID, h.Hurricane, u.SSN, s.Status, sh.Shelter, b.Booking_Date_Time "
           "FROM Bookings b "
           "JOIN Hurricanes h ON b.Hurricane = h.Hurricane_ID "
           "JOIN Users u ON b.User = u.User_ID "
           "JOIN Status s ON b.Status = s.Status_ID "
           "JOIN Shelters sh ON b.Shelter = sh.Shelter_ID "
           "WHERE b.Booking_ID = :booking_id;";
}

// ------------------------------------------------------------------------------------------------------------------------------------------------
// Query to update the current tableview
// ------------------------------------------------------------------------------------------------------------------------------------------------
QString BookingsCRUD::buildViewTableCommand() const {
    return "INSERT INTO Bookings (Hurricane, User, Status, Shelter, Booking_Date_Time) "
           "VALUES (:hurricane_id, :user, :status_id, :shelter_id, :booking_date_time)";
}
