#include "userscrud.h"

UsersCRUD::UsersCRUD() {

}
UsersCRUD::~UsersCRUD() {

}

bool UsersCRUD::add(const Entity &entity){
    try {
        const Users* users = dynamic_cast<const Users*>(&entity);
        if (!users) {
            throw std::exception ("Invalid Object");
        }
        QSqlQuery query;
        query.prepare(buildInsertCommand());
        query.bindValue(":address", users->getAddress() );
        query.bindValue(":blocked", users->getBlocked());
        query.bindValue(":contactnumber", users->getContact_Number());
        query.bindValue(":fname", users->getFirst_Name());
        query.bindValue(":lname", users->getLast_Name());
        query.bindValue(":middlename", users->getMiddle_Name());
        query.bindValue(":pass", users->getPassword());
        query.bindValue(":role", users->getRole());
        query.bindValue(":ssn", users->getSSN());

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

bool UsersCRUD::edit(const Entity &entity) {
    try {
        const Users* users = dynamic_cast<const Users*>(&entity);
        if (!users) {
            throw std::exception ("Invalid Object");
        }
        QSqlQuery query;
        query.prepare(buildUpdateCommand());
        query.bindValue(":address", users->getAddress() );
        query.bindValue(":blocked", users->getBlocked());
        query.bindValue(":contactnumber", users->getContact_Number());
        query.bindValue(":fname", users->getFirst_Name());
        query.bindValue(":lname", users->getLast_Name());
        query.bindValue(":middlename", users->getMiddle_Name());
        query.bindValue(":pass", users->getPassword());
        query.bindValue(":role", users->getRole());
        query.bindValue(":ssn", users->getSSN());
        query.bindValue(":user_id", users->getUser_ID());
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

bool UsersCRUD::delete_(const Entity &entity) {
    try {
        const Users* users = dynamic_cast<const Users*>(&entity);
        if (!users) {
            throw std::exception ("Invalid Object");
        }
        QSqlQuery query;
        query.prepare(buildDeleteCommand());
        query.bindValue(":user_id", users->getUser_ID());
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

bool UsersCRUD::view(const Entity &entity, Entity &newentity) const {
    try {
        const Users* users = dynamic_cast<const Users*>(&entity);
        if (!users) {
            throw std::exception ("Invalid Object");
        }
        QSqlQuery query;
        query.prepare(buildInsertCommand());
        query.bindValue(":user_id", users->getUser_ID());
        if (!query.exec()) {
            throw std::runtime_error("something went wrong: " + query.lastError().text().toStdString());
        }
        if (!query.next()) {
            qDebug("User Not Found");
        }

        Users* mutableUser = dynamic_cast<Users*>(&newentity);
        if (!mutableUser) {
            throw std::exception ("Invalid Object");
        }
        mutableUser->setAddress(query.value().toString);
        mutableUser->setBlocked(query.value().toBool);
        mutableUser->setContact_Number(query.value().toString);
        mutableUser->setFirst_Name(query.value().toString);
        mutableUser->setLast_Name(query.value().toString);
        mutableUser->setMiddle_Name(query.value().toString);
        mutableUser->setPassword(query.value().toString);
        mutableUser->setRole(query.value().toString);
        mutableUser->setSSN(query.value().toString);
        mutableUser->setUser_ID(query.value().toInt);

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

QString UsersCRUD::viewTable() {

}

QString UsersCRUD::buildDeleteCommand() {

}

QString UsersCRUD::buildInsertCommand() {

}
QString UsersCRUD::buildSelectCommand() {

}

QString UsersCRUD::buildUpdateCommand() {

}

QString UsersCRUD::buildViewTableCommand() {

}

QString UsersCRUD::getTableName() {
    return "Users";
}
