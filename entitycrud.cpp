#include "entitycrud.h"

QSqlQueryModel *EntityCRUD::viewTable() {
    try {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery(buildViewTableCommand());

        return model;
    } catch (const std::exception& e) {
        throw e;
        return nullptr;
    }
}

void EntityCRUD::setRole(const QString& roleString) {
    if (roleString == "None") {
        role_ = Role::None;
    } else if (roleString == "Administrator") {
        role_ = Role::Administrator;
    } else if (roleString == "Employee") {
        role_ = Role::Employee;
    } else if (roleString == "Bookie") {
        role_ = Role::Bookie;
    } else {
        role_ = Role::None;
    }
}

Role EntityCRUD::getRole() const {
    return role_;
}
