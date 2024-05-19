#ifndef ENTITYCRUD_H
#define ENTITYCRUD_H

#include <memory>
#include <QDebug>
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

class EntityCRUD {
public:
    enum class Role {
        None = 0,
        Administrator = 1,
        Employee = 2,
        Bookie = 3
    };
    virtual ~EntityCRUD() = default;
    virtual bool add(const Entity& entity) = 0;
    virtual bool edit(const Entity& entity) = 0;
    virtual bool delete_(const Entity& entity) = 0;
    virtual bool view(const Entity& entity, Entity& newentity) const = 0 ;
    QSqlQueryModel* viewTable();
    void setRole(int r);
    Role getRole() const;

protected:
    virtual QString getTableName() const = 0;
    virtual QString buildInsertCommand() const = 0;
    virtual QString buildUpdateCommand() const = 0;
    virtual QString buildDeleteCommand() const = 0;
    virtual QString buildSelectCommand() const = 0;
    virtual QString buildViewTableCommand() const = 0;
private:
    Role role;
};

#endif // ENTITYCRUD_H
