#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QDate>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>
#include <QTimer>
#include <QSqlError>



// MainWindow constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->CustomerMaps->setSource(QUrl(QStringLiteral("qrc:/maps.qml")));
    ui->CustomerMaps->show();

    // Initialize view and table
    ui->SW_Workers_Screen->setCurrentIndex(0);
    ui->L_Workers_TableHeaderTitle->setText("Select an Item to Continue");
    ui->F_Workers_MenuItems->hide();
    setCurrentTable(0);
    populateComboBox(ui->CB_Customer_Region, "Regions", "Region", "Region_ID");
    int selectedDistrictID = ui->CB_Customer_Region->currentData().toInt();
    populateComboBoxWithRegion(ui->CB_Customer_Location, "Locations", "Location", "Location_ID", selectedDistrictID);
    populateComboBoxWithRegion(ui->CB_Customer_Shelter, "Shelters", "Name", "Shelter_ID", selectedDistrictID);
    ui->SW_Authentication->setCurrentIndex(0);

    // Display current date and time
    QDate date = QDate::currentDate();
    QString dateString = date.toString("dd-MM-yyyy");
    ui->L_Header_DateTitle->setText("Current Date: " + dateString);


    //set updating time
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateCurrentTime);
    timer->start(1000);






}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateCurrentTime()
{
    QTime time = QTime::currentTime();
    QString timeString = time.toString("hh:mm:ss");
    ui->L_Header_TimeTitle->setText("Current Time: " + timeString);
}

// Function to set the current table index
void MainWindow::setCurrentTable(int tableIndex) {
    currentTable = tableIndex;
}

// Function to get the current table index
int MainWindow::getCurrentTable() const {
    return currentTable;
}

// Function to refresh the table view based on the category
void MainWindow::refreshTable(Category category) {
    switch(category) {
    case Users:
        refreshUsersTable();
        break;
    case Shelters:
        refreshSheltersTable();
        break;
    case Bookings:
        refreshBookingsTable();
        break;
    case Hurricanes:
        refreshHurricanesTable();
        break;
    case Locations:
        refreshLocationsTable();
        break;
    }
}

// Function to set up UI based on the role
void MainWindow::setupUI(Role role) {
    switch(role) {
    case Admin:
        // Setup admin UI
        break;
    case Employee:
        // Setup employee UI
        break;
    case Customer:
        // Setup customer UI
        break;
    }
}

// Function to change the worker screen based on the category
void MainWindow::changeWorkerScreen(Category category) {
    switch(category) {
    case Users:
        on_PB_Workers_Screen_Users_clicked();
        break;
    case Shelters:
        on_PB_Workers_Screen_Shelters_clicked();
        break;
    case Bookings:
        on_PB_Workers_Screen_Bookings_clicked();
        break;
    case Hurricanes:
        on_PB_Workers_Screen_Hurricanes_clicked();
        break;
    case Locations:
        on_PB_Workers_Screen_Location_clicked();
        break;
    }
}

// Function to perform an action based on the category and action
void MainWindow::performAction(Category category, Action action) {
    switch(category) {
    case Users:
        switch(action) {
        case Add:
            // Add user
            break;
        case Edit:
            // Edit user
            break;
        case Delete:
            // Delete user
            break;
        }
        break;
    case Shelters:
        switch(action) {
        case Add:
            // Add shelter
            break;
        case Edit:
            // Edit shelter
            break;
        case Delete:
            // Delete shelter
            break;
        }
        break;
    case Bookings:
        switch(action) {
        case Add:
            // Add booking
            break;
        case Edit:
            // Edit booking
            break;
        case Delete:
            // Delete booking
            break;
        }
        break;
    case Hurricanes:
        switch(action) {
        case Add:
            // Add hurricane
            break;
        case Edit:
            // Edit hurricane
            break;
        case Delete:
            // Delete hurricane
            break;
        }
        break;
    case Locations:
        switch(action) {
        case Add:
            // Add location
            break;
        case Edit:
            // Edit location
            break;
        case Delete:
            // Delete location
            break;
        }
        break;
    }
}

// Function to confirm an action based on the category and action
void MainWindow::confirmAction(Category category, Action action) {
    switch(category) {
    case Users:
        switch(action) {
        case Add:
            // Confirm add user
            break;
        case Edit:
            // Confirm edit user
            break;
        case Delete:
            // Confirm delete user
            break;
        }
        break;
    case Shelters:
        switch(action) {
        case Add:
            // Confirm add shelter
            break;
        case Edit:
            // Confirm edit shelter
            break;
        case Delete:
            // Confirm delete shelter
            break;
        }
        break;
    case Bookings:
        switch(action) {
        case Add:
            // Confirm add booking
            break;
        case Edit:
            // Confirm edit booking
            break;
        case Delete:
            // Confirm delete booking
            break;
        }
        break;
    case Hurricanes:
        switch(action) {
        case Add:
            // Confirm add hurricane
            break;
        case Edit:
            // Confirm edit hurricane
            break;
        case Delete:
            // Confirm delete hurricane
            break;
        }
        break;
    case Locations:
        switch(action) {
        case Add:
            // Confirm add location
            break;
        case Edit:
            // Confirm edit location
            break;
        case Delete:
            // Confirm delete location
            break;
        }
        break;
    }
}

// Function to hide all UI elements
void MainWindow::hideAllUI() {
    // Implement hiding of all UI elements
}

// Helper function to populate combo boxes
void MainWindow::populateComboBox(QComboBox *comboBox, const QString &tableName, const QString &displayColumn, const QString &idColumn) {
    try {
        QSqlQuery query("SELECT " + idColumn + ", " + displayColumn + " FROM " + tableName);
        if (!query.exec()) {
            throw std::runtime_error("Failed to fetch data from the database.");
        }

        comboBox->clear();
        while (query.next()) {
            int id = query.value(0).toInt();
            QString name = query.value(1).toString();
            comboBox->addItem(name, id);
        }
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", QString("Failed to populate combo box: %1").arg(e.what()), QMessageBox::Cancel);
    }
}

// Helper function to populate combo boxes with region filter
void MainWindow::populateComboBoxWithRegion(QComboBox *comboBox, const QString &tableName, const QString &displayColumn, const QString &idColumn, int regionID) {
    try {
        QString queryStr = "SELECT " + idColumn + ", " + displayColumn + " FROM " + tableName;
        if (!tableName.compare("Locations", Qt::CaseInsensitive)) {
            queryStr += " WHERE Region = :regionID";
        } else if (!tableName.compare("Shelters", Qt::CaseInsensitive)) {
            queryStr += " INNER JOIN Locations ON Shelters.Location = Locations.Location_ID WHERE Locations.Region = :regionID";
        }

        QSqlQuery query;
        query.prepare(queryStr);
        if (!tableName.compare("Locations", Qt::CaseInsensitive) || !tableName.compare("Shelters", Qt::CaseInsensitive)) {
            query.bindValue(":regionID", regionID);
        }

        if (!query.exec()) {
            throw std::runtime_error("Failed to fetch data from the database.");
        }

        comboBox->clear();
        while (query.next()) {
            int id = query.value(0).toInt();
            QString name = query.value(1).toString();
            comboBox->addItem(name, id);
        }
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", QString("Failed to populate combo box: %1").arg(e.what()), QMessageBox::Cancel);
    }
}

// Function to refresh Users table
void MainWindow::refreshUsersTable() {
    try {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT "
                        "U.SSN AS 'SSN', "
                        "R.Role AS 'Role', "
                        "U.First_Name AS 'First Name', "
                        "U.Last_Name AS 'Last Name', "
                        "U.Address AS 'Address', "
                        "U.Email AS 'Email', "
                        "U.Phone AS 'Phone', "
                        "U.Region AS 'Region', "
                        "U.Password AS 'Password' "
                        "FROM Users U "
                        "INNER JOIN Roles R ON U.Role = R.Role_ID");
        if (model->lastError().isValid()) {
            throw std::runtime_error(model->lastError().text().toStdString());
        }
        ui->TV_Workers_TableView->setModel(model);
    } catch (const std::exception &e) {
        QMessageBox::critical(this, "Error", QString("Failed to refresh Users table: %1").arg(e.what()), QMessageBox::Cancel);
    }
}

// Function to refresh Shelters table
void MainWindow::refreshSheltersTable() {
    try {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT "
                        "S.Shelter_ID AS 'Shelter ID', "
                        "S.Name AS 'Name', "
                        "S.Address AS 'Address', "
                        "S.Phone AS 'Phone', "
                        "S.Website AS 'Website', "
                        "L.Location AS 'Location' "
                        "FROM Shelters S "
                        "INNER JOIN Locations L ON S.Location = L.Location_ID");
        if (model->lastError().isValid()) {
            throw std::runtime_error(model->lastError().text().toStdString());
        }
        ui->TV_Workers_TableView->setModel(model);
    } catch (const std::exception &e) {
        QMessageBox::critical(this, "Error", QString("Failed to refresh Shelters table: %1").arg(e.what()), QMessageBox::Cancel);
    }
}

// Function to refresh Bookings table
void MainWindow::refreshBookingsTable() {
    try {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT "
                        "B.Booking_ID AS 'Booking ID', "
                        "B.User_ID AS 'User ID', "
                        "B.Shelter_ID AS 'Shelter ID', "
                        "B.Start_Date AS 'Start Date', "
                        "B.End_Date AS 'End Date', "
                        "B.Status AS 'Status' "
                        "FROM Bookings B");
        if (model->lastError().isValid()) {
            throw std::runtime_error(model->lastError().text().toStdString());
        }
        ui->TV_Workers_TableView->setModel(model);
    } catch (const std::exception &e) {
        QMessageBox::critical(this, "Error", QString("Failed to refresh Bookings table: %1").arg(e.what()), QMessageBox::Cancel);
    }
}

// Function to refresh Hurricanes table
void MainWindow::refreshHurricanesTable() {
    try {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT "
                        "H.Hurricane_ID AS 'Hurricane ID', "
                        "H.Name AS 'Name', "
                        "H.Category AS 'Category', "
                        "H.Status AS 'Status', "
                        "H.Landfall_Date AS 'Landfall Date' "
                        "FROM Hurricanes H");
        if (model->lastError().isValid()) {
            throw std::runtime_error(model->lastError().text().toStdString());
        }
        ui->TV_Workers_TableView->setModel(model);
    } catch (const std::exception &e) {
        QMessageBox::critical(this, "Error", QString("Failed to refresh Hurricanes table: %1").arg(e.what()), QMessageBox::Cancel);
    }
}

// Function to refresh Locations table
void MainWindow::refreshLocationsTable() {
    try {
        QSqlQueryModel *model = new QSqlQueryModel;
        model->setQuery("SELECT "
                        "L.Location_ID AS 'Location ID', "
                        "L.Location AS 'Location', "
                        "L.Region AS 'Region' "
                        "FROM Locations L");
        if (model->lastError().isValid()) {
            throw std::runtime_error(model->lastError().text().toStdString());
        }
        ui->TV_Workers_TableView->setModel(model);
    } catch (const std::exception &e) {
        QMessageBox::critical(this, "Error", QString("Failed to refresh Locations table: %1").arg(e.what()), QMessageBox::Cancel);
    }
}


// Function to handle button clicks for worker screens
void MainWindow::on_PB_Workers_Screen_Users_clicked() {
    setCurrentTable(Users);
    refreshTable(Users);
    ui->SW_Workers_Screen->setCurrentIndex(1); // Assuming 1 is the index for Users screen
}

void MainWindow::on_PB_Workers_Screen_Shelters_clicked() {
    setCurrentTable(Shelters);
    refreshTable(Shelters);
    ui->SW_Workers_Screen->setCurrentIndex(2); // Assuming 2 is the index for Shelters screen
}

void MainWindow::on_PB_Workers_Screen_Bookings_clicked() {
    setCurrentTable(Bookings);
    refreshTable(Bookings);
    ui->SW_Workers_Screen->setCurrentIndex(3); // Assuming 3 is the index for Bookings screen
}

void MainWindow::on_PB_Workers_Screen_Hurricanes_clicked() {
    setCurrentTable(Hurricanes);
    refreshTable(Hurricanes);
    ui->SW_Workers_Screen->setCurrentIndex(4); // Assuming 4 is the index for Hurricanes screen
}

void MainWindow::on_PB_Workers_Screen_Location_clicked() {
    setCurrentTable(Locations);
    refreshTable(Locations);
    ui->SW_Workers_Screen->setCurrentIndex(5); // Assuming 5 is the index for Locations screen
}
