#ifndef HURRICANES_H
#define HURRICANES_H

#include "entity.h"

class Hurricanes : public Entity
{
public:
    Hurricanes();
    ~Hurricanes();

    void setHurricane_ID(int hurricane_id);
    void setHurricane(const QString &hurricane);
    void setCategory(int category);
    void setHurricaneDate(const QString &hurricanedate);
    void setFlag(const QString &flag);
    void setActive(bool active);

    int getHurricane_ID() const;
    QString getHurricane() const;
    int getCategory() const;
    QString getHurricaneDate() const;
    QString getFlag() const;
    bool getActive() const;

private:
    int Hurricane_ID;
    QString Hurricane;
    int Category;
    QString HurricaneDate;
    QString Flag;
    bool Active;
};

#endif // HURRICANES_H
