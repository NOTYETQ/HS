#include "hurricanes.h"

Hurricanes::Hurricanes() {

}

Hurricanes::~Hurricanes() {

}

void Hurricanes::setHurricane_ID(int hurricane_id){
    Hurricane_ID = hurricane_id;
}

void Hurricanes::setHurricane(const QString &hurricane){
    Hurricane = hurricane;
}

void Hurricanes::setCategory(int category){
    Category = category;
}

void Hurricanes::setHurricaneDate(const QString &hurricanedate){
    HurricaneDate = hurricanedate;
}

void Hurricanes::setFlag(const QString &flag){
    Flag = flag;
}

void Hurricanes::setActive(bool active) {
    Active = active;
}


int Hurricanes::getHurricane_ID() const{
    return Hurricane_ID;
}

QString Hurricanes::getHurricane() const{
    return Hurricane;
}

int Hurricanes::getCategory() const{
    return Category;
}

QString Hurricanes::getHurricaneDate() const{
    return HurricaneDate;
}

QString Hurricanes::getFlag() const{
    return Flag;
}

bool Hurricanes::getActive() const {
    return Active;
}
