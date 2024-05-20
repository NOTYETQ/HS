// #include "mainwindow.h"
// #include "ui_mainwindow.h"

// #include <QLabel>
// #include <QDate>
// #include <QVBoxLayout>
// #include <QMessageBox>
// #include <QSqlQuery>
// #include <QDebug>
// #include <QTimer>
// #include <QSqlError>



// // MainWindow constructor
// MainWindow::MainWindow(QWidget *parent)
//     : QMainWindow(parent)
//     , ui(new Ui::MainWindow)
// {
//     ui->setupUi(this);
//     ui->CustomerMaps->setSource(QUrl(QStringLiteral("qrc:/maps.qml")));
//     ui->CustomerMaps->show();

//     // Initialize view and table
//     ui->SW_Workers_Screen->setCurrentIndex(0);
//     ui->L_Workers_TableHeaderTitle->setText("Select an Item to Continue");
//     ui->F_Workers_MenuItems->hide();
//     setCurrentTable(0);
//     populateComboBox(ui->CB_Customer_Region, "Regions", "Region", "Region_ID");
//     int selectedDistrictID = ui->CB_Customer_Region->currentData().toInt();
//     populateComboBoxWithRegion(ui->CB_Customer_Location, "Locations", "Location", "Location_ID", selectedDistrictID);
//     populateComboBoxWithRegion(ui->CB_Customer_Shelter, "Shelters", "Name", "Shelter_ID", selectedDistrictID);
//     ui->SW_Authentication->setCurrentIndex(0);

//     // Display current date and time
//     QDate date = QDate::currentDate();
//     QString dateString = date.toString("dd-MM-yyyy");
//     ui->L_Header_DateTitle->setText("Current Date: " + dateString);


//     //set updating time
//     QTimer *timer = new QTimer(this);
//     connect(timer, &QTimer::timeout, this, &MainWindow::updateCurrentTime);
//     timer->start(1000);



// }


// MainWindow::~MainWindow()
// {
//     delete ui;
// }

// void MainWindow::updateCurrentTime()
// {
//     QTime time = QTime::currentTime();
//     QString timeString = time.toString("hh:mm:ss");
//     ui->L_Header_TimeTitle->setText("Current Time: " + timeString);
// }

// // Function to set the current table index
// void MainWindow::setCurrentTable(int tableIndex) {
//     currentTable = tableIndex;
// }

// // Function to get the current table index
// int MainWindow::getCurrentTable() const {
//     return currentTable;
// }

// // Function to refresh the table view based on the category
// void MainWindow::refreshTable(Category category) {
//     switch(category) {
//     case Users:
//         refreshUsersTable();
//         break;
//     case Shelters:
//         refreshSheltersTable();
//         break;
//     case Bookings:
//         refreshBookingsTable();
//         break;
//     case Hurricanes:
//         refreshHurricanesTable();
//         break;
//     case Locations:
//         refreshLocationsTable();
//         break;
//     }
// }

// // Function to set up UI based on the role
// void MainWindow::setupUI(Role role) {
//     switch(role) {
//     case Admin:
//         // Setup admin UI
//         break;
//     case Employee:
//         // Setup employee UI
//         break;
//     case Customer:
//         // Setup customer UI
//         break;
//     }
// }

// // Function to change the worker screen based on the category
// void MainWindow::changeWorkerScreen(Category category) {
//     switch(category) {
//     case Users:
//         on_PB_Workers_Screen_Users_clicked();
//         break;
//     case Shelters:
//         on_PB_Workers_Screen_Shelters_clicked();
//         break;
//     case Bookings:
//         on_PB_Workers_Screen_Bookings_clicked();
//         break;
//     case Hurricanes:
//         on_PB_Workers_Screen_Hurricanes_clicked();
//         break;
//     case Locations:
//         on_PB_Workers_Screen_Location_clicked();
//         break;
//     }
// }

// // Function to perform an action based on the category and action
// void MainWindow::performAction(Category category, Action action) {
//     switch(category) {
//     case Users:
//         switch(action) {
//         case Add:
//             // Add user
//             break;
//         case Edit:
//             // Edit user
//             break;
//         case Delete:
//             // Delete user
//             break;
//         }
//         break;
//     case Shelters:
//         switch(action) {
//         case Add:
//             // Add shelter
//             break;
//         case Edit:
//             // Edit shelter
//             break;
//         case Delete:
//             // Delete shelter
//             break;
//         }
//         break;
//     case Bookings:
//         switch(action) {
//         case Add:
//             // Add booking
//             break;
//         case Edit:
//             // Edit booking
//             break;
//         case Delete:
//             // Delete booking
//             break;
//         }
//         break;
//     case Hurricanes:
//         switch(action) {
//         case Add:
//             // Add hurricane
//             break;
//         case Edit:
//             // Edit hurricane
//             break;
//         case Delete:
//             // Delete hurricane
//             break;
//         }
//         break;
//     case Locations:
//         switch(action) {
//         case Add:
//             // Add location
//             break;
//         case Edit:
//             // Edit location
//             break;
//         case Delete:
//             // Delete location
//             break;
//         }
//         break;
//     }
// }

// // Function to confirm an action based on the category and action
// void MainWindow::confirmAction(Category category, Action action) {
//     switch(category) {
//     case Users:
//         switch(action) {
//         case Add:
//             // Confirm add user
//             break;
//         case Edit:
//             // Confirm edit user
//             break;
//         case Delete:
//             // Confirm delete user
//             break;
//         }
//         break;
//     case Shelters:
//         switch(action) {
//         case Add:
//             // Confirm add shelter
//             break;
//         case Edit:
//             // Confirm edit shelter
//             break;
//         case Delete:
//             // Confirm delete shelter
//             break;
//         }
//         break;
//     case Bookings:
//         switch(action) {
//         case Add:
//             // Confirm add booking
//             break;
//         case Edit:
//             // Confirm edit booking
//             break;
//         case Delete:
//             // Confirm delete booking
//             break;
//         }
//         break;
//     case Hurricanes:
//         switch(action) {
//         case Add:
//             // Confirm add hurricane
//             break;
//         case Edit:
//             // Confirm edit hurricane
//             break;
//         case Delete:
//             // Confirm delete hurricane
//             break;
//         }
//         break;
//     case Locations:
//         switch(action) {
//         case Add:
//             // Confirm add location
//             break;
//         case Edit:
//             // Confirm edit location
//             break;
//         case Delete:
//             // Confirm delete location
//             break;
//         }
//         break;
//     }
// }

// // Function to hide all UI elements
// void MainWindow::hideAllUI() {
//     // main middle screen for tableviews
//     ui->SW_Workers_Screen->hide();
//     ui->TV_Workers->hide();

//     //forms
//     ui->F_EditProfile->hide();
//     ui->F_Customer_AddBooking->hide();
//     ui->F_SignUp->hide();
//     ui->F_Login->hide();
//     ui->F_EditProfile->hide();
//     ui->F_Customer_Menu->hide();
//     ui->F_Workers_TableHeader->hide();

// //right side buttons
//     ui->PB_Workers_View->hide();
//     ui->PB_Workers_Add->hide();
//     ui->PB_Workers_Edit->hide();
//     ui->PB_Workers_Delete->hide();

// //left side buttons
//     ui->PB_Workers_Screen_Bookings->hide();
//     ui->PB_Workers_Screen_Hurricanes->hide();
//     ui->PB_Workers_Screen_Location->hide();
//     ui->PB_Workers_Screen_Shelters->hide();
//     ui->PB_Workers_Screen_Users->hide();

// //top part
//     ui->L_Header_TimeTitle->hide();
//     ui->L_Header_DateTitle->hide();
//     ui->L_Header_CurrentUserTitle->hide();
//     ui->PB_Header_Logout->hide();
//     ui->PB_Header_EditProfile->hide();

//     //make frame with title and line for search edit and searc button and filter combobox then hide it

// }

// // Helper function to populate combo boxes
// void MainWindow::populateComboBox(QComboBox *comboBox, const QString &tableName, const QString &displayColumn, const QString &idColumn) {
//     try {
//         QSqlQuery query("SELECT " + idColumn + ", " + displayColumn + " FROM " + tableName);
//         if (!query.exec()) {
//             throw std::runtime_error("Failed to fetch data from the database.");
//         }

//         comboBox->clear();
//         while (query.next()) {
//             int id = query.value(0).toInt();
//             QString name = query.value(1).toString();
//             comboBox->addItem(name, id);
//         }
//     } catch (const std::exception& e) {
//         QMessageBox::critical(this, "Error", QString("Failed to populate combo box: %1").arg(e.what()), QMessageBox::Cancel);
//     }
// }

// // Helper function to populate combo boxes with region filter
// void MainWindow::populateComboBoxWithRegion(QComboBox *comboBox, const QString &tableName, const QString &displayColumn, const QString &idColumn, int regionID) {
//     try {
//         QString queryStr = "SELECT " + idColumn + ", " + displayColumn + " FROM " + tableName;
//         if (!tableName.compare("Locations", Qt::CaseInsensitive)) {
//             queryStr += " WHERE Region = :regionID";
//         } else if (!tableName.compare("Shelters", Qt::CaseInsensitive)) {
//             queryStr += " INNER JOIN Locations ON Shelters.Location = Locations.Location_ID WHERE Locations.Region = :regionID";
//         }

//         QSqlQuery query;
//         query.prepare(queryStr);
//         if (!tableName.compare("Locations", Qt::CaseInsensitive) || !tableName.compare("Shelters", Qt::CaseInsensitive)) {
//             query.bindValue(":regionID", regionID);
//         }

//         if (!query.exec()) {
//             throw std::runtime_error("Failed to fetch data from the database.");
//         }

//         comboBox->clear();
//         while (query.next()) {
//             int id = query.value(0).toInt();
//             QString name = query.value(1).toString();
//             comboBox->addItem(name, id);
//         }
//     } catch (const std::exception& e) {
//         QMessageBox::critical(this, "Error", QString("Failed to populate combo box: %1").arg(e.what()), QMessageBox::Cancel);
//     }
// }

// // Function to refresh Users table
// void MainWindow::refreshUsersTable() {
//     try {
//         QSqlQueryModel *model = new QSqlQueryModel;
//         model->setQuery("SELECT "
//                         "U.SSN AS 'SSN', "
//                         "R.Role AS 'Role', "
//                         "U.First_Name AS 'First Name', "
//                         "U.Last_Name AS 'Last Name', "
//                         "U.Address AS 'Address', "
//                         "U.Email AS 'Email', "
//                         "U.Phone AS 'Phone', "
//                         "U.Region AS 'Region', "
//                         "U.Password AS 'Password' "
//                         "FROM Users U "
//                         "INNER JOIN Roles R ON U.Role = R.Role_ID");
//         if (model->lastError().isValid()) {
//             throw std::runtime_error(model->lastError().text().toStdString());
//         }
//         // Adjust column widths
//         ui->TV_Workers->resizeColumnsToContents();

//         // Set column alignment
//         ui->TV_Workers->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//         ui->TV_Workers->setModel(model);
//     } catch (const std::exception &e) {
//         QMessageBox::critical(this, "Error", QString("Failed to refresh Users table: %1").arg(e.what()), QMessageBox::Cancel);
//     }
// }

// // Function to refresh Shelters table
// void MainWindow::refreshSheltersTable() {
//     try {
//         QSqlQueryModel *model = new QSqlQueryModel;
//         model->setQuery("SELECT "
//                         "S.Shelter_ID AS 'Shelter ID', "
//                         "S.Name AS 'Name', "
//                         "S.Address AS 'Address', "
//                         "S.Phone AS 'Phone', "
//                         "S.Website AS 'Website', "
//                         "L.Location AS 'Location' "
//                         "FROM Shelters S "
//                         "INNER JOIN Locations L ON S.Location = L.Location_ID");
//         if (model->lastError().isValid()) {
//             throw std::runtime_error(model->lastError().text().toStdString());
//         }

//         // Adjust column widths
//         ui->TV_Workers->resizeColumnsToContents();

//         // Set column alignment
//         ui->TV_Workers->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//         ui->TV_Workers->setModel(model);
//     } catch (const std::exception &e) {
//         QMessageBox::critical(this, "Error", QString("Failed to refresh Shelters table: %1").arg(e.what()), QMessageBox::Cancel);
//     }
// }

// // Function to refresh Bookings table
// void MainWindow::refreshBookingsTable() {
//     try {
//         QSqlQueryModel *model = new QSqlQueryModel;
//         model->setQuery("SELECT "
//                         "B.Booking_ID AS 'Booking ID', "
//                         "B.User_ID AS 'User ID', "
//                         "B.Shelter_ID AS 'Shelter ID', "
//                         "B.Start_Date AS 'Start Date', "
//                         "B.End_Date AS 'End Date', "
//                         "B.Status AS 'Status' "
//                         "FROM Bookings B");
//         if (model->lastError().isValid()) {
//             throw std::runtime_error(model->lastError().text().toStdString());
//         }

//         // Adjust column widths
//         ui->TV_Workers->resizeColumnsToContents();

//         // Set column alignment
//         ui->TV_Workers->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//         ui->TV_Workers->setModel(model);
//     } catch (const std::exception &e) {
//         QMessageBox::critical(this, "Error", QString("Failed to refresh Bookings table: %1").arg(e.what()), QMessageBox::Cancel);
//     }
// }

// // Function to refresh Hurricanes table
// void MainWindow::refreshHurricanesTable() {
//     try {
//         QSqlQueryModel *model = new QSqlQueryModel;
//         model->setQuery("SELECT "
//                         "H.Hurricane_ID AS 'Hurricane ID', "
//                         "H.Name AS 'Name', "
//                         "H.Category AS 'Category', "
//                         "H.Status AS 'Status', "
//                         "H.Landfall_Date AS 'Landfall Date' "
//                         "FROM Hurricanes H");
//         if (model->lastError().isValid()) {
//             throw std::runtime_error(model->lastError().text().toStdString());
//         }

//         // Adjust column widths
//         ui->TV_Workers->resizeColumnsToContents();

//         // Set column alignment
//         ui->TV_Workers->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//         ui->TV_Workers->setModel(model);
//     } catch (const std::exception &e) {
//         QMessageBox::critical(this, "Error", QString("Failed to refresh Hurricanes table: %1").arg(e.what()), QMessageBox::Cancel);
//     }
// }

// // Function to refresh Locations table
// void MainWindow::refreshLocationsTable() {
//     try {
//         QSqlQueryModel *model = new QSqlQueryModel;
//         model->setQuery("SELECT "
//                         "L.Location_ID AS 'Location ID', "
//                         "L.Location AS 'Location', "
//                         "L.Region AS 'Region' "
//                         "FROM Locations L");
//         if (model->lastError().isValid()) {
//             throw std::runtime_error(model->lastError().text().toStdString());
//         }

//         // Adjust column widths
//         ui->TV_Workers->resizeColumnsToContents();

//         // Set column alignment
//         ui->TV_Workers->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
//         ui->TV_Workers->setModel(model);
//     } catch (const std::exception &e) {
//         QMessageBox::critical(this, "Error", QString("Failed to refresh Locations table: %1").arg(e.what()), QMessageBox::Cancel);
//     }
// }


// // Function to handle button clicks for worker screens
// void MainWindow::on_PB_Workers_Screen_Users_clicked()
// {
//     ui->F_Workers_MenuItems->show();
//     ui->L_Workers_TableHeaderTitle->setText("Users");
//     // sets it to the tablescreen
//     ui->SW_Workers_Screen->setCurrentIndex(0);
//     refreshUsersTable();
//     setCurrentTable(5);
// }


// void MainWindow::on_PB_Workers_Screen_Shelters_clicked()
// {
//     ui->F_Workers_MenuItems->show();
//     ui->L_Workers_TableHeaderTitle->setText("Shelters");
//     ui->SW_Workers_Screen->setCurrentIndex(0);
//     refreshSheltersTable();
//     setCurrentTable(4);
// }


// void MainWindow::on_PB_Workers_Screen_Bookings_clicked()
// {
//     ui->F_Workers_MenuItems->show();
//     ui->L_Workers_TableHeaderTitle->setText("Bookings");
//     ui->SW_Workers_Screen->setCurrentIndex(0);
//     refreshBookingsTable();
//     setCurrentTable(1);
// }


// void MainWindow::on_PB_Workers_Screen_Hurricanes_clicked()
// {
//     ui->F_Workers_MenuItems->show();
//     ui->L_Workers_TableHeaderTitle->setText("Hurricanes");
//     ui->SW_Workers_Screen->setCurrentIndex(0);
//     refreshHurricanesTable();
//     setCurrentTable(2);
// }


// void MainWindow::on_PB_Workers_Screen_Location_clicked()
// {
//     ui->F_Workers_MenuItems->show();
//     ui->L_Workers_TableHeaderTitle->setText("Locations");
//     ui->SW_Workers_Screen->setCurrentIndex(0);
//     refreshLocationsTable();
//     setCurrentTable(3);
// }

// void MainWindow::on_PB_Login_Login_clicked()
// {
//     int ssn = ui->LE_Login_SSN->text().toInt();
//     QString password = ui->LE_Login_Password->text();

//     int login = userManager.Login(ssn, password);

//     if (login != -1) {
//         ui->SW_Authentication->setCurrentIndex(1);


//         switch (login){

//         case(1)://admin //workers
//             ui->SW_RoleScreenChanger->setCurrentIndex(0);

//             break;

//         case (2)://employee
//             ui->SW_RoleScreenChanger->setCurrentIndex(0);


//             break;

//         case(3): //customer

//             ui->SW_RoleScreenChanger->setCurrentIndex(1);

//             break;


//         default://does not exist
//             return;
//         }

//     }
// }


// void MainWindow::on_PB_Header_Logout_clicked()
// {
//     userManager.Logout();//will have to change this since classse changed
//     ui->SW_Authentication->setCurrentIndex(0);
// }

// //implementation for the add

// /*

// // Retrieve user input from QLineEdit widgets
//     QString ssn = ui->lineEditSSN->text();
//     QString firstName = ui->lineEditFirstName->text();
//     QString lastName = ui->lineEditLastName->text();
//     QString address = ui->lineEditAddress->text();
//     // Retrieve user input from QComboBox
//     Role role = static_cast<Role>(ui->comboBoxRole->currentIndex()); // Assuming comboBoxRole is populated with Role enum values

//     // Validate user input (e.g., check if required fields are not empty)

//     // Create a UserInfo object with the collected data
//     UserInfo userInfo;
//     userInfo.ssn = ssn;
//     userInfo.fname = firstName;
//     userInfo.lname = lastName;
//     userInfo.address = address;
//     userInfo.role = role;

//     // Call the AddUser function to insert the user into the database
//     Administrators admin; // Assuming AddUser is a member function of the Administrators class
//     admin.AddUser(userInfo);

//     // Provide feedback to the user (e.g., show a message box)
//     QMessageBox::information(this, "Success", "User added successfully.");

// //edit button


// void MainWindow::onEditUserClicked() {

// // Make the SSN field read-only since it shouldn't be edited
//     ui->lineEditSSN->setDisabled(true);


//     // Retrieve user input from QLineEdit widgets
//     QString ssn = ui->lineEditSSN->text();
//     QString firstName = ui->lineEditFirstName->text();
//     QString lastName = ui->lineEditLastName->text();
//     QString address = ui->lineEditAddress->text();
//     QString contactNumber = ui->lineEditContactNumber->text();
//     QString password = ui->lineEditPassword->text();
//     bool blocked = ui->checkBoxBlocked->isChecked(); // Assuming there's a checkbox for blocked status
//     Role role = static_cast<Role>(ui->comboBoxRole->currentIndex()); // Assuming comboBoxRole is populated with Role enum values

//     // Validate user input (e.g., check if required fields are not empty)

//     // Create a UserInfo object with the collected data
//     UserInfo userInfo;
//     userInfo.ssn = ssn;
//     userInfo.fname = firstName;
//     userInfo.lname = lastName;
//     userInfo.address = address;
//     userInfo.contactnumber = contactNumber;
//     userInfo.password = password;
//     userInfo.blocked = blocked;
//     userInfo.role = role;

//     // Call the EditUser function to update the user in the database
//     Administrators admin; // Assuming EditUser is a member function of the Administrators class
//     admin.EditUser(userInfo);

//     // Provide feedback to the user (e.g., show a message box)
//     QMessageBox::information(this, "Success", "User edited successfully.");
// }
//     //put this at the top where setupui(this) is
//      connect(ui->editUserButton, &QPushButton::clicked, this, &MainWindow::onEditUserClicked);


//     //delete user
// void MainWindow::onDeleteUserClicked() {
//     // Get the selection model from the QTableView
//     QItemSelectionModel *selectionModel = ui->userTableView->selectionModel();

//     // Check if a row is selected
//     if (!selectionModel->hasSelection()) {
//         QMessageBox::warning(this, "Delete User", "Please select a user to delete.");
//         return;
//     }

//     // Get the index of the selected row
//     QModelIndex selectedIndex = selectionModel->currentIndex();

//     // Retrieve the SSN from the selected row (assuming SSN is in the first column)
//     QString ssn = selectedIndex.sibling(selectedIndex.row(), 0).data().toString();

//     // Create a UserInfo object with the SSN
//     UserInfo userInfo;
//     userInfo.ssn = ssn;

//     // Call the DeleteUser function to remove the user from the database
//     Users users; // Assuming DeleteUser is a member function of the Users class
//     users.DeleteUser(userInfo);

//     // Remove the selected row from the model
//     ui->userTableView->model()->removeRow(selectedIndex.row());

//     // Provide feedback to the user
//     QMessageBox::information(this, "Success", "User deleted successfully.");


// }

//    connect(ui->deleteButton, &QPushButton::clicked, this, &MainWindow::onDeleteUserClicked);

//  */


