#ifndef BOOKINGSCRUD_H
#define BOOKINGSCRUD_H

#include "entitycrud.h"
#include "bookings.h"

class BookingsCRUD : public EntityCRUD {
public:
    BookingsCRUD();
    ~BookingsCRUD();
    virtual bool add(const Entity& entity) override;
    virtual bool edit(const Entity& entity) override;
    virtual bool delete_(const Entity& entity) override;
    virtual bool view(const Entity& entity, Entity& newentity) const override;
    bool hasActiveBooking(int user_id);
protected:
    virtual QString getTableName() const override;
    virtual QString buildInsertCommand() const override;
    virtual QString buildUpdateCommand() const override;
    virtual QString buildDeleteCommand() const override;
    virtual QString buildSelectCommand() const override;
    virtual QString buildViewTableCommand() const override;
};

#endif // BOOKINGSCRUD_H
