#ifndef BOOKINGSCRUD_H
#define BOOKINGSCRUD_H

#include "entitycrud.h"
#include "bookings.h"

class BookingsCRUD : public EntityCRUD
{
public:
    BookingsCRUD();
    virtual bool add(const Entity& entity) override;
    virtual bool edit(const Entity& entity) override;
    virtual bool delete_(const Entity& entity) override;
    virtual bool view(const Entity& entity) override;
    virtual QSqlQueryModel* viewTable();

protected:
    virtual QString getTableName() const override;
    virtual QString buildInsertCommand(const Entity& entity) const override;
    virtual QString buildUpdateCommand(const Entity& entity) const override;
    virtual QString buildDeleteCommand(const Entity& entity) const override;
    virtual QString buildSelectCommand(const Entity& entity) const override;
    virtual QString buildViewTableCommand() const override;
};

#endif // BOOKINGSCRUD_H
