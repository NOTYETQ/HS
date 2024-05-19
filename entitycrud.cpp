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

// QSqlQuery EntityCRUD::executeQuery(const QString& command, Entity &entity) {
//     try {
//         if (command.isEmpty()) {
//             throw ValidationException("No Command Found!");
//         }

//         QSqlQuery query;
//         query.prepare(command);

//         if (!query.exec()) {
//             throw QueryException("Unable to Execute Query: " + query.lastError().text().toStdString());
//         }

//         if (command.indexOf("SELECT") != -1) {
//             qDebug() << "Select query Found.";
//             QSqlRecord record = query.record();

//             while (query.next()) {
//                 for (int i = 0; i < record.count(); ++i) {
//                     QString columnName = record.fieldName(i);
//                     QVariant value = query.value(i);

//                     // Use setterMap_ for generic data population
//                     auto setter = entity.setterMap_.find(columnName.toStdString());
//                     if (setter != entity.setterMap_.end()) {
//                         try {
//                             // Call the appropriate setter function with error handling
//                             (setter->second)(value);
//                         } catch (const std::exception& e) {
//                             qDebug() << "Error setting value for column '" << columnName << "': " << e.what();
//                             // Potentially re-throw or handle the error here
//                         }
//                     } else {
//                         qDebug() << "Warning: No setter found for column '" << columnName << "'";
//                     }
//                 }
//             }
//         } else {
//             // Handle non-SELECT operations (you can customize this)
//             qDebug() << "Non-SELECT query executed successfully.";
//         }

//         return query; // Return the QSqlQuery object
//     } catch (const ValidationException& e) {
//         qDebug() << "Validation Error: " << e.what();
//     } catch (const QueryException& e) {
//         qDebug() << "Query Error: " << e.what();
//     } catch (const std::exception& e) {
//         qDebug() << "Standard Exception: " << e.what();
//     }

//     return QSqlQuery(); // Return empty QSqlQuery on errors
// }

