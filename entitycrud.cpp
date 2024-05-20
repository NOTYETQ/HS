#include "entitycrud.h"

QSqlQueryModel* EntityCRUD::viewTable() {
    QSqlQueryModel *model = nullptr;
    try {
        model = new QSqlQueryModel;
        model->setQuery(buildViewTableCommand());

        if (model->lastError().isValid()) {
            throw std::runtime_error(model->lastError().text().toStdString());
        }

        return model;
    } catch (const std::exception& e) {
        delete model; // Clean up in case of an error
        qWarning() << "Error in viewTable: " << e.what(); // Log the error
        return nullptr;
    }
}


void EntityCRUD::setRole(const QString& roleString) {
    if (roleString == "0") {
        role_ = Role::None;
    } else if (roleString == "1") {
        role_ = Role::Administrator;
    } else if (roleString == "2") {
        role_ = Role::Employee;
    } else if (roleString == "3") {
        role_ = Role::Bookie;
    } else {
        role_ = Role::None;
    }
}

Role EntityCRUD::getRole() const {
    return role_;
}
