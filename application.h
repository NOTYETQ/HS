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

private slots:
    // Combobox populators
    // void onRegionChanged(int index);
    // void onLocationChanged(int index);
    void loginClicked();
    void signUpClicked();
    void signUp();
    void cancelSignUp();

private:
    Ui::Application *ui;

    // Initializers for CRUD operations
    DatabaseManager db;
    Session session;
    BookingsCRUD CRUD_Booking;
    HurricanesCRUD CRUD_Hurricane;
    Locations CRUD_Location;
    SheltersCRUD CRUD_Shelters;
    UsersCRUD CRUD_Users;

    // Combobox initializers
    int getIdFromComboBox(const QComboBox* comboBox) const;
    void initializeComboBoxes();
    void populateCB_Region(QComboBox* comboBox);
    void populateCB_Location(QComboBox* comboBox, int regionId);
    void populateCB_Shelter(QComboBox* comboBox, int locationId);

    int customer_RegionId;
    int customer_LocationId;
    int worker_Shelters_RegionId;
    int worker_Bookings_RegionId;
    int worker_Bookings_LocationId;

};

#endif // APPLICATION_H
