#ifndef ENTITYCRUD_H
#define ENTITYCRUD_H

#include <memory>
#include <QDebug>
#include <QMetaEnum>
#include <QString>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QVariant>
#include <stdexcept>
#include <unordered_map>

#include "entity.h"

enum class Role {
    None,
    Administrator,
    Employee,
    Bookie
};

class EntityCRUD {
public:
    Role role_ = Role::None;

    void setRole(const QString& roleString);
    Role getRole() const;

    virtual ~EntityCRUD() = default;
    virtual bool add(const Entity& entity) = 0;
    virtual bool edit(const Entity& entity) = 0;
    virtual bool delete_(const Entity& entity) = 0;
    virtual bool view(const Entity& entity, Entity& newentity) const = 0 ;
    QSqlQueryModel* viewTable();

protected:
    virtual QString getTableName() const = 0;
    virtual QString buildInsertCommand() const = 0;
    virtual QString buildUpdateCommand() const = 0;
    virtual QString buildDeleteCommand() const = 0;
    virtual QString buildSelectCommand() const = 0;
    virtual QString buildViewTableCommand() const = 0;
};

#endif // ENTITYCRUD_H
