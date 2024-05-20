#ifndef HURRICANESCRUD_H
#define HURRICANESCRUD_H

#include "entitycrud.h"
#include "hurricanes.h"

class HurricanesCRUD : public EntityCRUD {
public:
    HurricanesCRUD();
    ~HurricanesCRUD();
    virtual bool add(const Entity& entity) override;
    virtual bool edit(const Entity& entity) override;
    virtual bool delete_(const Entity& entity) override;
    virtual bool view(const Entity& entity, Entity& newentity) const override;
    bool isHurricaneActive(int hurricane_id);
protected:
    virtual QString getTableName() const override;
    virtual QString buildInsertCommand() const override;
    virtual QString buildUpdateCommand() const override;
    virtual QString buildDeleteCommand() const override;
    virtual QString buildSelectCommand() const override;
    virtual QString buildViewTableCommand() const override;
};

#endif // HURRICANESCRUD_H
