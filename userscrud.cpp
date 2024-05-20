#include "userscrud.h"

UsersCRUD::UsersCRUD() {
    setRole("None");
    qDebug("UsersCRUD Constructed");
    getRole();
}
UsersCRUD::~UsersCRUD() {
    qDebug("UsersCRUD Deconstructed");
}

bool UsersCRUD::add(const Entity &entity){
    try {
        const Users* users = dynamic_cast<const Users*>(&entity);
        if (!users) {
            throw DatabaseException ("Invalid Object");
        }
        if (users->getAddress().isEmpty() ||
            users->getContact_Number().isEmpty() || users->getFirst_Name().isEmpty() ||
            users->getLast_Name().isEmpty() || users->getMiddle_Name().isEmpty() ||
            users->getPassword().isEmpty() ||
            users->getSSN().isEmpty()) {
            // Handle the case where any of the values are empty
            throw std::invalid_argument("One or more values are empty.");
            // Or you can return from the function, throw an exception, or handle it in any appropriate way
        }

        if (userExists(users->getSSN())) {
            throw;
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
    } catch (std::runtime_error) {
        throw;
        return false;
    } catch (std::exception) {
        throw;
        return false;
    }
}

bool UsersCRUD::edit(const Entity &entity) {
    try {
        const Users* users = dynamic_cast<const Users*>(&entity);
        if (!users) {
            throw DatabaseException("Invalid Object");
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

bool UsersCRUD::delete_(const Entity &entity) {
    try {
        const Users* users = dynamic_cast<const Users*>(&entity);
        if (!users) {
            throw DatabaseException ("Invalid Object");
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

bool UsersCRUD::view(const Entity &entity, Entity &newentity) const {
    try {
        const Users* users = dynamic_cast<const Users*>(&entity);
        if (!users) {
            throw DatabaseException ("Invalid Object");
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
            throw DatabaseException ("Invalid Object");
        }
        mutableUser->setAddress(query.value("Address").toString());
        mutableUser->setBlocked(query.value("Blocked").toBool());
        mutableUser->setContact_Number(query.value("Contact_Number").toString());
        mutableUser->setFirst_Name(query.value("First_Name").toString());
        mutableUser->setLast_Name(query.value("Last_Name").toString());
        mutableUser->setMiddle_Name(query.value("Middle_Name").toString());
        mutableUser->setPassword(query.value("Password").toString());
        mutableUser->setRole(query.value("Role").toString());
        mutableUser->setSSN(query.value("SSN").toString());
        mutableUser->setUser_ID(query.value("User_ID").toInt());

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

QString UsersCRUD::buildInsertCommand() const {
    QString queryStr;
    switch (getRole()) {
    case Role::Bookie:
        throw std::runtime_error("You do not have permission");
    case Role::None:
        queryStr = "INSERT INTO Users (SSN, Role, First_Name, Middle_Name, Last_Name, Address, Contact_Number, Password) "
                   "VALUES (:ssn, 3 ,:fname, :middlename, :lname, :address, :contactnumber, :pass)";
        break;
    case Role::Employee:
        queryStr = "INSERT INTO Users (SSN, First_Name, Middle_Name, Last_Name, Address, Contact_Number, Blocked, Password) "
                   "VALUES (:ssn, :fname, :middlename, :lname, :address, :contactnumber, :blocked, :pass)";
        break;
    case Role::Administrator:
        queryStr = "INSERT INTO Users (SSN, Role, First_Name, Middle_Name, Last_Name, Address, Contact_Number, Blocked, Password) "
                   "VALUES (:ssn, :role, :fname, :middlename, :lname, :address, :contactnumber, :blocked, :pass)";
        break;
    default:
        throw std::runtime_error("Invalid role");
    }
    return queryStr;
}

QString UsersCRUD::buildDeleteCommand() const {
    if (getRole() != Role::Administrator) {
        throw std::runtime_error("You do not have permission to delete users");
    }

    return "DELETE FROM Users WHERE User_ID = :user_id";
}

QString UsersCRUD::buildUpdateCommand() const {
    QString queryStr;
    switch (getRole()) {
    case Role::Bookie:
        queryStr = "UPDATE Users SET Address = :address, Contact_Number = :contactnumber, Password = :pass WHERE User_ID = :user_id";
        break;
    case Role::Employee:
        queryStr = "UPDATE Users SET First_Name = :fname, Middle_Name = :middlename, Last_Name = :lname, "
                   "Address = :address, Contact_Number = :contactnumber, Blocked = :blocked, Password = :pass "
                   "WHERE User_ID = :user_id";
        break;
    case Role::Administrator:
        queryStr = "UPDATE Users SET SSN = :ssn, Role = :role, First_Name = :fname, Middle_Name = :middlename, "
                   "Last_Name = :lname, Address = :address, Contact_Number = :contactnumber, Blocked = :blocked, "
                   "Password = :pass WHERE User_ID = :user_id";
        break;
    default:
        throw std::runtime_error("Invalid role");
    }
    return queryStr;
}

QString UsersCRUD::buildSelectCommand() const{
    QString querystr = "SELECT User_ID, SSN, Role, First_Name, MiddleName, Last_Name, Address, Contact_Number, Blocked, Password WHERE User_ID = :user_id";
    return querystr;
}

QString UsersCRUD::buildViewTableCommand() const {
    QString queryStr;
    switch (getRole()) {
    case Role::Bookie:
        throw std::runtime_error("You do not have permission");
    case Role::None:
        throw std::runtime_error("You do not have permission");
    case Role::Employee:
        queryStr = "SELECT u.User_ID, u.SSN, r.Role, u.First_Name, u.Middle_Name, u.Last_Name, u.Address, "
                   "u.Contact_Number, u.Blocked, u.Password "
                   "FROM Users u "
                   "JOIN Roles r ON u.Role = r.Role_ID "
                   "WHERE u.Role = 3";
        break;
    case Role::Administrator:
        queryStr = "SELECT u.User_ID, u.SSN, r.Role, u.First_Name, u.Middle_Name, u.Last_Name, u.Address, "
                   "u.Contact_Number, u.Blocked, u.Password "
                   "FROM Users u "
                   "JOIN Roles r ON u.Role = r.Role_ID";
        break;
    default:
        throw std::runtime_error("Invalid role");
    }
    return queryStr;
}

QString UsersCRUD::getTableName() const{
    return "Users";
}


bool UsersCRUD::userExists(const QString &ssn) {
    try {
        QSqlQuery query;
        query.prepare("SELECT User_ID FROM Users WHERE SSN = :ssn");
        query.bindValue(":ssn", ssn);
        if (!query.exec()) {
            throw std::runtime_error("Something went wrong: " + query.lastError().text().toStdString());
        }

        if (query.next()) {
            if (query.next()) {
                throw std::runtime_error("Multiple users found with the same SSN");
            } else {
                qDebug("User exists");
                return true;
            }
        } else {
            qDebug("User does not exist");
            return false;
        }
    } catch (const std::exception& e) {
        throw std::runtime_error("Error checking user existence: " + std::string(e.what()));
    }
}

bool UsersCRUD::passwordMatch(const QString &password, const QString &passwordconfirm) {
    try {
        if (password != passwordconfirm) {
            throw std::runtime_error("Passwords do not match");
        }
        return true;
    } catch (const std::exception& e) {
        throw std::runtime_error("Error matching passwords: " + std::string(e.what()));
    }
}

void UsersCRUD::resetPassword(int userId) {
    try {
        QSqlQuery query;
        query.prepare("UPDATE Users SET Password = :password WHERE User_ID = :user_id");
        query.bindValue(":password", "123456789");
        query.bindValue(":user_id", userId);

        if (!query.exec()) {
            throw std::runtime_error("Error resetting password: " + query.lastError().text().toStdString());
        }
    } catch (const std::exception& e) {
        throw std::runtime_error("Error resetting password: " + std::string(e.what()));
    }
}
