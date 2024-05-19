#ifndef SHELTERSCRUD_H
#define SHELTERSCRUD_H

#include "entitycrud.h".h"
#include "shelters.h"

class SheltersCRUD : public EntityCRUD {
public:
    SheltersCRUD();
    virtual bool add(const Entity& entity) override;
    virtual bool edit(const Entity& entity) override;
    virtual bool delete_(const Entity& entity) override;
    virtual bool view(const Entity& entity, Entity& newentity) const override;
protected:
    virtual QString getTableName() const override;
    virtual QString buildInsertCommand() const override;
    virtual QString buildUpdateCommand() const override;
    virtual QString buildDeleteCommand() const override;
    virtual QString buildSelectCommand() const override;
    virtual QString buildViewTableCommand() const override;
};

#endif // SHELTERSCRUD_H
