#include "locationscrud.h"

LocationsCRUD::LocationsCRUD() {
    qDebug("LocationsCRUD Constructed");
    getRole();
}

LocationsCRUD::~LocationsCRUD() {
    qDebug("LocationsCRUD Destructed");
}

bool LocationsCRUD::add(const Entity &entity){
    try {
        if (getRole() != Role::Administrator) {
            throw std::runtime_error ("You do not have permision");
        }

        const Locations* locations = dynamic_cast<const Locations*>(&entity);
        if (!locations) {
            throw DatabaseException("Invalid Object");
        }
        QSqlQuery query;
        query.prepare(buildInsertCommand());
        query.bindValue(":location", locations->getLocation() );
        query.bindValue(":region", locations->getRegion());

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

bool LocationsCRUD::edit(const Entity &entity) {
    try {

        if (getRole() != Role::Administrator) {
            throw std::runtime_error ("You do not have permision");
        }

        const Locations* locations = dynamic_cast<const Locations*>(&entity);
        if (!locations) {
            throw DatabaseException("Invalid Object");
        }
        QSqlQuery query;
        query.prepare(buildUpdateCommand());
        query.bindValue(":location", locations->getLocation() );
        query.bindValue(":location_id", locations->getLocation_ID());
        query.bindValue(":region", locations->getRegion());
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

bool LocationsCRUD::delete_(const Entity &entity) {
    try {

        if (getRole() != Role::Administrator) {
            throw std::runtime_error ("You do not have permision");
        }

        const Locations* locations = dynamic_cast<const Locations*>(&entity);
        if (!locations) {
            throw DatabaseException("Invalid Object");
        }
        QSqlQuery query;
        query.prepare(buildDeleteCommand());
        query.bindValue(":location_id", locations->getLocation_ID());
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

bool LocationsCRUD::view(const Entity &entity, Entity &newentity) const {
    try {

        if (getRole() != Role::Administrator) {
            throw std::runtime_error ("You do not have permision");
        }

        const Locations* locations = dynamic_cast<const Locations*>(&entity);
        if (!locations) {
            throw DatabaseException("Invalid object");
        }
        QSqlQuery query;
        query.prepare(buildInsertCommand());
        query.bindValue(":location_id", locations->getLocation_ID());
        if (!query.exec()) {
            throw std::runtime_error("something went wrong: " + query.lastError().text().toStdString());
        }
        if (!query.next()) {
            qDebug("Location Not Found");
        }

        Locations* mutableLocation = dynamic_cast<Locations*>(&newentity);
        if (!mutableLocation) {
            throw DatabaseException("Invalid Object");
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

QString LocationsCRUD::buildDeleteCommand() const {
    QString queryStr = "DELETE FROM Locations WHERE Location_ID = :location_id";
    return queryStr;
}

QString LocationsCRUD::buildInsertCommand() const {
    QString queryStr = "INSERT INTO Locations (Location, Region)"
                       "Values (:location :region)";
    return queryStr;
}
QString LocationsCRUD::buildSelectCommand() const {
    QString queryStr = "SELECT "
                       "L.Location_ID"
                       "R.Region"
                       "L.Location"
                       "FROM "
                       "Regions R "
                       "JOIN "
                       "Locations L ON L.Region = R.Region_ID;";
    return queryStr;

}

QString LocationsCRUD::buildUpdateCommand() const {
    QString queryStr = "UPDATE Locations SET Region = :region, Location = :loaction WHERE Location_ID = :location_ID";
    return queryStr;
}

QString LocationsCRUD::buildViewTableCommand() const {
    if (getRole() != Role::Administrator) {
        throw std::runtime_error ("You do not have permision");
    }
    QString query = "SELECT "
                    "R.Region AS 'Region', "
                    "L.Location AS 'Location' "
                    "FROM "
                    "Regions R "
                    "JOIN "
                    "Locations L ON L.Region = R.Region_ID;";
    return query;
}

QString LocationsCRUD::getTableName() const {
    return "Locations";
}
