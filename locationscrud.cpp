#include "locationscrud.h"

LocationsCRUD::LocationsCRUD() {

}

LocationsCRUD::~LocationsCRUD() {
}

bool LocationsCRUD::add(const Entity &entity){
    try {
        const Locations* locations = dynamic_cast<const Locations*>(&entity);
        if (!Locations) {
            throw std::exception ("Invalid Object");
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
    catch (std::runtime_error) {
        throw;
        return false;
    }
    catch (std::exception) {
        throw;
        return false;
    }
}

bool LocationsCRUD::edit(const Entity &entity) {
    try {
        const Locations* locations = dynamic_cast<const Locations*>(&entity);
        if (!Locations) {
            throw std::exception ("Invalid Object");
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
    catch (std::runtime_error) {
        throw;
        return false;
    }
    catch (std::exception) {
        throw;
        return false;
    }
}

bool LocationsCRUD::delete_(const Entity &entity) {
    try {
        const Locations* locations = dynamic_cast<const Locations*>(&entity);
        if (!Locations) {
            throw std::exception ("Invalid Object");
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
    catch (std::runtime_error) {
        throw;
        return false;
    }
    catch (std::exception) {
        throw;
        return false;
    }
}

bool LocationsCRUD::view(const Entity &entity, Entity &newentity) const {
    try {
        const Locations* locations = dynamic_cast<const Locations*>(&entity);
        if (!Locations) {
            throw std::exception ("Invalid Object");
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
            throw std::exception ("Invalid Object");
        }
        // setters here

        qDebug("Success");
        return true;
    }
    catch (std::runtime_error) {
        throw;
        return false;
    }
    catch (std::exception) {
        throw;
        return false;
    }
}

QString LocationsCRUD::viewTable() {

}

QString LocationsCRUD::buildDeleteCommand() {

}

QString LocationsCRUD::buildInsertCommand() {

}
QString LocationsCRUD::buildSelectCommand() {

}

QString LocationsCRUD::buildUpdateCommand() {

}

QString LocationsCRUD::buildViewTableCommand() {

}

QString LocationsCRUD::getTableName() {
    return "Locations";
}
