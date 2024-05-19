#include "hurricanescrud.h"

HurricanesCRUD::HurricanesCRUD() {

}
HurricanesCRUD::~HurricanesCRUD() {

}

bool HurricanesCRUD::add(const Entity &entity){
    try {
        const Hurricanes* hurricanes = dynamic_cast<const Hurricanes*>(&entity);
        if (!hurricanes) {
            throw std::exception ("Invalid Object");
        }
        QSqlQuery query;
        query.prepare(buildInsertCommand());
        query.bindValue(":category", hurricanes->getCategory() );
        query.bindValue(":flag", hurricanes->getFlag());
        query.bindValue(":hurricane", hurricanes->getHurricane());
        query.bindValue(":date", hurricanes->getHurricaneDate());

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

bool HurricanesCRUD::edit(const Entity &entity) {
    try {
        const Hurricanes* hurricanes = dynamic_cast<const Hurricanes*>(&entity);
        if (!Hurricanes) {
            throw std::exception ("Invalid Object");
        }
        QSqlQuery query;
        query.prepare(buildUpdateCommand());
        query.bindValue(":category", hurricanes->getCategory() );
        query.bindValue(":flag", hurricanes->getFlag());
        query.bindValue(":hurricane", hurricanes->getHurricane());
        query.bindValue(":date", hurricanes->getHurricaneDate());
        query.bindValue(":hurricane_id", hurricanes->getHurricane_ID());
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

bool HurricanesCRUD::delete_(const Entity &entity) {
    try {
        const Hurricanes* hurricanes = dynamic_cast<const Hurricanes*>(&entity);
        if (!Hurricanes) {
            throw std::exception ("Invalid Object");
        }
        QSqlQuery query;
        query.prepare(buildDeleteCommand());
        query.bindValue(":hurricane_id", hurricanes->getHurricane_ID());
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

bool HurricanesCRUD::view(const Entity &entity, Entity &newentity) const {
    try {
        const Hurricanes* hurricanes = dynamic_cast<const Hurricanes*>(&entity);
        if (!Hurricanes) {
            throw std::exception ("Invalid Object");
        }
        QSqlQuery query;
        query.prepare(buildInsertCommand());
        query.bindValue(":hurricane_id", hurricanes->getHurricane_ID());
        if (!query.exec()) {
            throw std::runtime_error("something went wrong: " + query.lastError().text().toStdString());
        }
        if (!query.next()) {
            qDebug("Hurricane Not Found");
        }

        Hurricanes* mutableHurricane = dynamic_cast<Hurricanes*>(&newentity);
        if (!mutableHurricane) {
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

QString HurricanesCRUD::viewTable() {

}

QString HurricanesCRUD::buildDeleteCommand() {

}

QString HurricanesCRUD::buildInsertCommand() {

}
QString HurricanesCRUD::buildSelectCommand() {

}

QString HurricanesCRUD::buildUpdateCommand() {

}

QString HurricanesCRUD::buildViewTableCommand() {

}

QString HurricanesCRUD::getTableName() {
    return "Hurricanes";
}
