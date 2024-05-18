#ifndef HURRICANES_H
#define HURRICANES_H
#include "entity.h"
#include <QDate>
s
class Hurricanes
{
public:
    Hurricanes();
    ~Hurricanes();

    void setHurricane_ID(int hurricane_id);
    void setHurricane(const QString &hurricane);
    void setCategory(int category);
    void setHurricaneDate(const QString &hurricanedate);
    void setFlag(const QString &flag);

    int getHurricane_ID() const;
    QString getHurricane() const;
    int getCategory() const;
    QDate getHurricaneDate() const;
    QString getFlag() const;

private:
    int Hurricane_ID;
    QString Hurricane;
    int Category;
    QDate HurricaneDate;
    QString Flag;
};

#endif // HURRICANES_H
