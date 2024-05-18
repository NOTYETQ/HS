#ifndef ENTITYCRUD_H
#define ENTITYCRUD_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSql>
#include <QString>
#include <QSqlRecord>
#include <stdexcept>
#include <QDebug>
#include <QSqlQueryModel>
#include "entity.h"

class EntityCRUD{
public:
    virtual ~EntityCRUD() = default;
    virtual bool add(const Entity& entity) = 0;
    virtual bool edit(const Entity& entity) = 0;
    virtual bool delete_(const Entity& entity) = 0;
    virtual bool view(const Entity& entity) = 0;
    virtual QSqlQueryModel* viewTable();

protected:
    virtual QString getTableName() const = 0;
    virtual QString buildInsertCommand(const Entity& entity) const = 0;
    virtual QString buildUpdateCommand(const Entity& entity) const = 0;
    virtual QString buildDeleteCommand(const Entity& entity) const = 0;
    virtual QString buildSelectCommand(const Entity& entity) const = 0;
    virtual QString buildViewTableCommand() const = 0;
    QSqlQuery executeQuery(const QString& command, Entity& entity);
};

#endif // ENTITYCRUD_H
