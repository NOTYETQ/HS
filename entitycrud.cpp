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

void EntityCRUD::setRole(int r) {
    role = r;
}

EntityCRUD::Role EntityCRUD::getRole() const {
    return role;
}
