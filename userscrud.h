#ifndef USERSCRUD_H
#define USERSCRUD_H

#include "entitycrud.h"
#include "users.h"

class UsersCRUD : public EntityCRUD {
public:
    UsersCRUD();
    ~UsersCRUD();
    virtual bool add(const Entity& entity) override;
    virtual bool edit(const Entity& entity) override;
    virtual bool delete_(const Entity& entity) override;
    virtual bool view(const Entity& entity, Entity& newentity) const override;
    bool userExists(const QString &ssn);
    bool passwordMatch(const QString &password, const QString &passwordconfirm);
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
