#ifndef LOCATIONSCRUD_H
#define LOCATIONSCRUD_H

#include "entitycrud.h"
#include "locations.h"

class LocationsCRUD : public EntityCRUD {
public:
    LocationsCRUD();
    ~LocationsCRUD();

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

#endif // LOCATIONSCRUD_H
