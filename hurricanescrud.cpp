#include "hurricanescrud.h"

HurricanesCRUD::HurricanesCRUD() {

}
HurricanesCRUD::~HurricanesCRUD() {

}

bool HurricanesCRUD::add(const Entity &entity){
    try {
        const Hurricanes* hurricanes = dynamic_cast<const Hurricanes*>(&entity);
        if (!hurricanes) {
            throw std::runtime_error (std::string("Invalid Object"));
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
        if (!hurricanes) {
            throw std::exception ();
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
        if (!hurricanes) {
            throw std::exception (std::string("Invalid Object"));
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
        if (!hurricanes) {
            throw std::exception (std::string("Invalid Object"));
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

QString HurricanesCRUD::buildDeleteCommand() const {
    QString queryStr = "DELETE FROM Hurricanes WHERE Hurricane_ID = :hurricaneID";
    return queryStr;
}

QString HurricanesCRUD::buildInsertCommand() const {
    QString queryStr = "INSERT INTO Hurricanes (Hurricane, Category, HurricaneDate, Flag, Active) "
                      "VALUES (:hurricane, :category, :date, :flag, :active)";
    return queryStr;
}

QString HurricanesCRUD::buildSelectCommand() const {
    QString queryStr = "SELECT "
                       "h.Hurricane_ID, "
                       "h.Hurricane, "
                       "h.Category"
                       "f.Flag, "
                       "h.HurricaneDate, "
                       "h.Active "
                       "FROM Hurricanes h "
                       "JOIN Flags f ON h.Flag = f.Flag_ID";
    return queryStr;
}

QString HurricanesCRUD::buildUpdateCommand() const {
    QString queryStr = "UPDATE Hurricanes "
                       "SET "
                       "Hurricane = :hurricane, "
                       "Category = :category, "
                       "Flag = :flag, "
                       "HurricaneDate = :date, "
                       "Active = :status "
                       "WHERE Hurricane_ID = :hurricane_ID";
    return queryStr;
}

QString HurricanesCRUD::buildViewTableCommand() const {
    QString queryStr = "DELETE FROM Shelters WHERE Shelter_ID = :shelter_id";
    return queryStr;
}

QString HurricanesCRUD::getTableName() const {
    return "Hurricanes";
}
