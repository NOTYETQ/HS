#include "session.h"

Session::Session() {}
Session::~Session() {}

bool Session::Login(const Users& user){
    try {
        QString ssn = user.getSSN();
        QString pass = user.getPassword();
        if (!verifyCredentials(ssn, pass)) {
            throw;
        } else {
            Current_User = user;
            setIsLoggedIn(true);
            ucrud.setRole(Current_User.getRole());
            qDebug("User Logged In");
            return true;
        }
    }
    catch (const std::runtime_error& e) {
        throw e;
        return false;
    } catch (const std::exception& e) {
        throw e;
        return false;
    }

}
bool Session::Logout() {
    try {
        if (getIsLoggedIn()) {
            // Clear user information from the Session
            Current_User = Users();
            ucrud.setRole("None");
            setIsLoggedIn(false);
            qDebug("User Logged Out");
        } else {
            throw DatabaseException("No User Logged In");
        }
    }
    catch (DatabaseException e) {
        throw e;
        return false;
    }
    catch (std::exception e) {
        throw e ;
        return false;
    }
}
bool Session::getIsLoggedIn() {
    return IsLoggedIn;
}

bool Session::setIsLoggedIn(bool loggedin){
    IsLoggedIn = loggedin;
}

Users Session::getCurrent_User() {
    return Current_User;
}

bool Session::verifyCredentials(const QString &ssn, const QString &password) {
    try {
        QSqlQuery query;
        query.prepare("SELECT User_ID FROM Users WHERE SSN = :ssn AND Password = :password");
        query.bindValue(":ssn", ssn);
        query.bindValue(":password", password);

        if (!query.exec()) {
            throw std::runtime_error("Error executing query: " + query.lastError().text().toStdString());
        }

        if (query.next()) {
            return true; // User exists and password matches
        } else {
            return false; // User not found or password does not match
        }
    } catch (const std::exception& e) {
        throw std::runtime_error("Error verifying credentials: " + std::string(e.what()));
        return false;
    }
}
