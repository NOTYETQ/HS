#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
class DatabaseManager
{
public:
    DatabaseManager();
    ~DatabaseManager();
    void openDatabase();
    void closeDatabase();
private:
    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H
