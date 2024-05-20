
#include "shelterscrud.h"

SheltersCRUD::SheltersCRUD() {

}

SheltersCRUD::~SheltersCRUD() {
}

bool SheltersCRUD::add(const Entity &entity){
    try {
        const Shelters* shelters = dynamic_cast<const Shelters*>(&entity);
        if (!shelters) {
            throw DatabaseException ("Invalid Object");
        }
        QSqlQuery query;
        query.prepare(buildInsertCommand());
        query.bindValue(":address", shelters->getAddress() );
        query.bindValue(":capacity", shelters->getCapacity());
        query.bindValue(":condition", shelters->getCondition());
        query.bindValue(":latitude", shelters->getLatitude());
        query.bindValue(":longitude", shelters->getLongitude());
        query.bindValue(":location", shelters->getLocation());
        query.bindValue(":remainingcapacity", shelters->getRemainingCapacity());
        query.bindValue(":shelter", shelters->getShelter());

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

bool SheltersCRUD::edit(const Entity &entity) {
    try {
        const Shelters* shelters = dynamic_cast<const Shelters*>(&entity);
        if (!shelters) {
            throw DatabaseException ("Invalid Object");
        }
        QSqlQuery query;
        query.prepare(buildUpdateCommand());

        query.bindValue(":address", shelters->getAddress() );
        query.bindValue(":capacity", shelters->getCapacity());
        query.bindValue(":condition", shelters->getCondition());
        query.bindValue(":latitude", shelters->getLatitude());
        query.bindValue(":longitude", shelters->getLongitude());
        query.bindValue(":location", shelters->getLocation());
        query.bindValue(":remainingcapacity", shelters->getRemainingCapacity());
        query.bindValue(":shelter", shelters->getShelter());
        query.bindValue(":shelter_id", shelters->getShelter_ID());

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

bool SheltersCRUD::delete_(const Entity &entity) {
    try {
        const Shelters* shelters = dynamic_cast<const Shelters*>(&entity);
        if (!shelters) {
            throw DatabaseException ("Invalid Object");
        }
        QSqlQuery query;
        query.prepare(buildDeleteCommand());
        query.bindValue(":shelter_id", shelters->getShelter_ID());
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

bool SheltersCRUD::view(const Entity &entity, Entity &newentity) const {
    try {
        const Shelters* shelters = dynamic_cast<const Shelters*>(&entity);
        if (!shelters) {
            throw DatabaseException("Invalid Object");
        }
        QSqlQuery query;
        query.prepare(buildSelectCommand());
        query.bindValue(":shelter_id", shelters->getShelter_ID());
        if (!query.exec()) {
            throw std::runtime_error("something went wrong: " + query.lastError().text().toStdString());
        }
        if (!query.next()) {
            qDebug("Shelter Not Found");
        }

        Shelters* mutableLocation = dynamic_cast<Shelters*>(&newentity);
        if (!mutableLocation) {
            throw DatabaseException ("Invalid Object");
        }
        // setters here

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

QString SheltersCRUD::buildDeleteCommand() const {
    QString queryStr = "DELETE FROM Shelters WHERE Shelter_ID = :shelter_id";
    return queryStr;
}

QString SheltersCRUD::buildInsertCommand() const {
    QString queryStr = "INSERT INTO Shelters (Shelter, Location, Address, `Condition`, Latitude, Longitude, Capacity) "
                       "VALUES (:shelter, :location, :address, :condition, :latitude, :longitude, :capacity)";
    return queryStr;
}
QString SheltersCRUD::buildSelectCommand() const {
    QString queryStr = "SELECT "
                       "s.Shelter_ID, "
                       "s.Shelter, "
                       "s.Location, "
                       "s.Address, "
                       "s.Condition, "
                       "s.Latitude, "
                       "s.Longitude, "
                       "s.Capacity, "
                       "s.Capacity - COALESCE((SELECT COUNT(*) FROM Bookings b "
                       "                       JOIN Status st ON b.Status = st.Status_ID "
                       "                       WHERE b.Shelter = s.Shelter_ID AND st.Status = 'Booked'), 0) AS Remaining_Capacity "
                       "FROM "
                       "Shelters s;";

    return queryStr;
}

QString SheltersCRUD::buildUpdateCommand() const {
    QString queryStr = "UPDATE Shelters "
                       "SET Shelter = :shelter, Location = :location, Address = :address, `Condition` = :condition, "
                       "Latitude = :latitude, Longitude = :longitude, Capacity = :capacity "
                       "WHERE Shelter_ID = :shelter_id";
    return queryStr;
}

QString SheltersCRUD::buildViewTableCommand() const {
    QString queryStr = "SELECT * FROM Shelters;";
    return queryStr;
}

QString SheltersCRUD::getTableName() const {
    return "Shelters";
}
