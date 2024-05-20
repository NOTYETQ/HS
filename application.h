#ifndef APPLICATION_H
#define APPLICATION_H

// Qt Items
#include <QMainWindow>
#include <QDebug>
#include <QMessageBox>
#include <QComboBox>
#include <QVariant>

// Crud Operations
#include "bookingscrud.h"
#include "hurricanescrud.h"
#include "locationscrud.h"
#include "shelterscrud.h"
#include "userscrud.h"

// Objects
#include "bookings.h"
#include "hurricanes.h"
#include "locations.h"
#include "shelterscrud.h"
#include "users.h"

// System Classes
#include "session.h"
#include "databasemanager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Application;
}
QT_END_NAMESPACE

class Application : public QMainWindow
{
    Q_OBJECT

public:
    Application(QWidget *parent = nullptr);
    ~Application();

    enum class Categories {
        Bookings,
        Hurricanes,
        Users,
        Locations,
        Shelters
    };

    Categories getCategory() const;
    void setCategory(Categories newCategory);


private slots:
    // Combobox populators
    // void onRegionChanged(int index);
    // void onLocationChanged(int index);
    void loginClicked();
    void signUpClicked();
    void signUp();
    void cancelSignUp();
    void editProfileClicked();
    void logout();
    void editProfileCancelled();
    void editProfileConfirm();

    void selectworkerscreen();
    void onBookingsButtonClicked();
    void onHurricanesButtonClicked();
    void onUsersButtonClicked();
    void onLocationsButtonClicked();
    void onSheltersButtonClicked();

    void on_PB_Workers_Add_clicked();

private:
    Ui::Application *ui;
    QSqlQueryModel *model;

    // Initializers for CRUD operations
    DatabaseManager db;
    Session session;
    BookingsCRUD CRUD_Booking;
    HurricanesCRUD CRUD_Hurricane;
    LocationsCRUD CRUD_Location;
    SheltersCRUD CRUD_Shelters;
    UsersCRUD CRUD_Users;

    Categories category;

    // Combobox initializers
    int getIdFromComboBox(const QComboBox* comboBox) const;
    void initializeComboBoxes();
    void populateCB_Region(QComboBox* comboBox);
    void populateCB_Location(QComboBox* comboBox, int regionId);
    void populateCB_Shelter(QComboBox* comboBox, int locationId);

    void showui();

    int customer_RegionId;
    int customer_LocationId;
    int worker_Shelters_RegionId;
    int worker_Bookings_RegionId;
    int worker_Bookings_LocationId;

    void handleEditAction();
    void handleAddAction();
    void handleDeleteAction();

};

#endif // APPLICATION_H
