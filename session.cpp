#include "session.h"

Session::Session() {
}

Session::~Session() {
}

bool Session::Login(const Users& loginAttempt) {
    try {
        // Call verifyCredentials to validate login and populate authenticatedUser
        if (!verifyCredentials(loginAttempt, Current_User)) {
            qDebug() << "Login failed: Invalid credentials provided.";
            return false;
        }
        qDebug() << "User Logged In";
        return true;
    } catch (const std::exception& e) {
        qCritical() << "Login failed: " << e.what();
        return false;
    }
}
bool Session::Logout() {
    try {
        if (getIsLoggedIn()) {
            // Clear user information from the Session
            Current_User = Users();
            setIsLoggedIn(false);
            qDebug("User Logged Out");
        } else {
            throw std::runtime_error("Logout failed: No user logged in.");
        }
    } catch (const DatabaseException& e) {
        throw e; // Re-throw DatabaseException for specific handling
    } catch (const std::exception& e) {
        throw std::runtime_error("Logout failed: An unexpected error occurred.");
    }

    return false; // Shouldn't be reached if no exceptions are thrown
}

bool Session::getIsLoggedIn() {
    return IsLoggedIn;
}

bool Session::setIsLoggedIn(bool loggedin) {
    IsLoggedIn = loggedin;
    return true; // Can return true for success (optional)
}

Users Session::getCurrent_User() {
    return Current_User;
}



bool Session::verifyCredentials(const Users& loginAttempt, Users& authenticatedUser) {
    try {
        QSqlQuery query;
        query.prepare("SELECT u.User_ID, u.SSN, u.Role, u.First_Name, u.Middle_Name, u.Last_Name, u.Address, u.Contact_Number, u.Blocked, u.Password "
                      "FROM Users u "
                      "JOIN Roles r ON u.Role = r.Role_ID "
                      "WHERE u.SSN = :ssn AND u.Password = :password;");


        query.bindValue(":ssn", loginAttempt.getSSN());
        query.bindValue(":password", loginAttempt.getPassword());

        if (!query.exec()) {
            throw std::runtime_error("Error executing query: " + query.lastError().text().toStdString());
        }

        if (!query.next()) {
            qDebug() << "User Not Found";
            return false;
        }

        // Populate authenticatedUser with data from the query
        authenticatedUser.setUser_ID(query.value("User_ID").toInt());
        authenticatedUser.setSSN(query.value("SSN").toString());
        authenticatedUser.setRole(query.value("Role").toString());
        authenticatedUser.setFirst_Name(query.value("First_Name").toString());
        authenticatedUser.setMiddle_Name(query.value("Middle_Name").toString());
        authenticatedUser.setLast_Name(query.value("Last_Name").toString());
        authenticatedUser.setAddress(query.value("Address").toString());
        authenticatedUser.setContact_Number(query.value("Contact_Number").toString());
        authenticatedUser.setBlocked(query.value("Blocked").toBool());
        authenticatedUser.setPassword(query.value("Password").toString());

        qDebug() << "Success";
        return true;
    } catch (const std::exception& e) {
        qCritical() << "Error verifying credentials: " << e.what();
        return false;
    }
}
