#include "databasemanager.h"
#include <QDebug>
#include <QSqlError>

DatabaseManager::DatabaseManager() {

}

DatabaseManager::~DatabaseManager(){
    closeDatabase();
}

void DatabaseManager::openDatabase() {
    try {
        if (db.isOpen()) {
            throw std::runtime_error("Database is open already.");
        }
        QString host = qgetenv("DB_HOST");
        QString port = qgetenv("DB_PORT");
        QString user = qgetenv("DB_USER");
        QString pass = qgetenv("DB_PASS");
        QString database = qgetenv("DB_DATABASE");

        if (host.isEmpty() || port.isEmpty() || user.isEmpty() || pass.isEmpty() || database.isEmpty()) {
            throw std::runtime_error("Environment variables for database configuration are not set.");
        }

        db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName(host);
        db.setPort(port.toInt());
        db.setUserName(user);
        db.setPassword(pass);
        db.setDatabaseName(database);

        if (!db.open()) {
            throw std::runtime_error(("Unable to connect to: " + db.databaseName()).toStdString());
        }
        qDebug() << "Database" << database << "connected successfully!";
    } catch (const std::exception &e) {
        qDebug() << "Exception:" << e.what();
    }
}

void DatabaseManager::closeDatabase() {
    if (db.isOpen()) {
        try {
            db.close();
        } catch (const std::exception &e) {
            qDebug() << "Exception:" << e.what();
        }
    } else {
        qDebug() << "Database is not open.";
    }
}
