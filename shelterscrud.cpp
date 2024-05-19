
#include "shelterscrud.h"

SheltersCRUD::SheltersCRUD() {

}

SheltersCRUD::~SheltersCRUD() {
}

bool SheltersCRUD::add(const Entity &entity){
    try {
        const Shelters* shelters = dynamic_cast<const Shelters*>(&entity);
        if (!Shelters) {
            throw std::exception ("Invalid Object");
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
    catch (std::runtime_error) {
        throw;
        return false;
    }
    catch (std::exception) {
        throw;
        return false;
    }
}

bool SheltersCRUD::edit(const Entity &entity) {
    try {
        const Shelters* shelters = dynamic_cast<const Shelters*>(&entity);
        if (!Shelters) {
            throw std::exception ("Invalid Object");
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
    catch (std::runtime_error) {
        throw;
        return false;
    }
    catch (std::exception) {
        throw;
        return false;
    }
}

bool SheltersCRUD::delete_(const Entity &entity) {
    try {
        const Shelters* shelters = dynamic_cast<const Shelters*>(&entity);
        if (!Shelters) {
            throw std::exception ("Invalid Object");
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
    catch (std::runtime_error) {
        throw;
        return false;
    }
    catch (std::exception) {
        throw;
        return false;
    }
}

bool SheltersCRUD::view(const Entity &entity, Entity &newentity) const {
    try {
        const Shelters* Shelters = dynamic_cast<const Shelters*>(&entity);
        if (!Shelters) {
            throw std::exception ("Invalid Object");
        }
        QSqlQuery query;
        query.prepare(buildInsertCommand());
        query.bindValue(":shelter_id", shelters->getShelter_ID());
        if (!query.exec()) {
            throw std::runtime_error("something went wrong: " + query.lastError().text().toStdString());
        }
        if (!query.next()) {
            qDebug("Shelter Not Found");
        }

        Shelters* mutableLocation = dynamic_cast<Shelters*>(&newentity);
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

QString SheltersCRUD::viewTable() {

}

QString SheltersCRUD::buildDeleteCommand() {

}

QString SheltersCRUD::buildInsertCommand() {

}
QString SheltersCRUD::buildSelectCommand() {

}

QString SheltersCRUD::buildUpdateCommand() {

}

QString SheltersCRUD::buildViewTableCommand() {

}

QString SheltersCRUD::getTableName() {
    return "Shelters";
}
