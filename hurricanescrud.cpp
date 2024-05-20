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
            throw DatabaseException("Something Wrong");
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

bool HurricanesCRUD::delete_(const Entity &entity) {
    try {
        const Hurricanes* hurricanes = dynamic_cast<const Hurricanes*>(&entity);
        if (!hurricanes) {
            throw DatabaseException("Invalid Object");
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

bool HurricanesCRUD::view(const Entity &entity, Entity &newentity) const {
    try {
        const Hurricanes* hurricanes = dynamic_cast<const Hurricanes*>(&entity);
        if (!hurricanes) {
            throw DatabaseException("Invalid Object");
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


bool HurricanesCRUD::isHurricaneActive(int hurricane_id) {
    try {
        QSqlQuery query;
        query.prepare("SELECT COUNT(*) FROM Hurricanes WHERE Hurricane_ID = :hurricane_id AND Active = 1");
        query.bindValue(":hurricane_id", hurricane_id);

        if (!query.exec()) {
            throw QueryError(query.lastError().text());
        }

        if (query.next()) {
            int count = query.value(0).toInt();
            if (count == 1) {
                return true; // One active hurricane
            } else if (count > 1) {
                throw std::exception("More than one hurricane is active.");
            } else {
                throw std::exception("No hurricanes are active.");
            }
        } else {
            throw std::exception("Failed to retrieve hurricane count.");
        }
    } catch (const std::exception& e) {
        qDebug() << "Standard Exception: " << e.what();
        QMessageBox::critical(nullptr, "Error", e.what());
    }
    return false;
}

