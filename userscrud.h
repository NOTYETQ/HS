#ifndef USERSCRUD_H
#define USERSCRUD_H

// Users CRUD
// Handles Datbase Operations for the Users Class and Users Table

#include "entitycrud.h"
#include "users.h"

// Inherits from the base class Entity CRUD
class UsersCRUD : public EntityCRUD {
public:
    UsersCRUD();
    ~UsersCRUD();
    // Overrides the pure functions from the Entity CRUD
    virtual bool add(const Entity& entity) override;
    virtual bool edit(const Entity& entity) override;
    virtual bool delete_(const Entity& entity) override;
    virtual bool view(const Entity& entity, Entity& newentity) const override;

    // Utility Functions
    // Checks if a user exists
    bool userExists(const QString &ssn);
    // Checks if 2 password Match
    bool passwordMatch(const QString &password, const QString &passwordconfirm);
    
    // Resets a password to a default value
    // dependent on User ID
    void resetPassword(int userid);
protected:
    virtual QString getTableName() const override;
    virtual QString buildInsertCommand() const override;
    virtual QString buildUpdateCommand() const override;
    virtual QString buildDeleteCommand() const override;
    virtual QString buildSelectCommand() const override;
    virtual QString buildViewTableCommand() const override;
};

#endif // USERSCRUD_H
