// #ifndef MAINWINDOW_H
// #define MAINWINDOW_H

// #include <QMainWindow>
// #include <QSqlQueryModel>
// #include <QComboBox>
// #include <QMessageBox>

// QT_BEGIN_NAMESPACE
// namespace Ui {
// class MainWindow;
// }
// QT_END_NAMESPACE

// enum Role {
//     Admin,
//     Employee,
//     Customer
// };

// enum Category {
//     Users,
//     Shelters,
//     Bookings,
//     Hurricanes,
//     Locations
// };

// enum Action {
//     Add,
//     Edit,
//     Delete
// };


// class MainWindow : public QMainWindow
// {
//     Q_OBJECT

// public:
//     MainWindow(QWidget *parent = nullptr);
//     ~MainWindow();

//      void updateCurrentTime();

// private slots:

//      void on_PB_Workers_Screen_Users_clicked(); // Slot for "Users" button click
//      void on_PB_Workers_Screen_Shelters_clicked(); // Slot for "Shelters" button click
//      void on_PB_Workers_Screen_Bookings_clicked(); // Slot for "Bookings" button click
//      void on_PB_Workers_Screen_Hurricanes_clicked(); // Slot for "Hurricanes" button click
//      void on_PB_Workers_Screen_Location_clicked(); // Slot for "Locations" button click


//      void performAction(Category category, Action action); // Declaration of performAction
//      void confirmAction(Category category, Action action);


// private:
//     Ui::MainWindow *ui;

//     int currentTable; // Variable to store the current table index

//     void setCurrentTable(int tableIndex); // Function to set the current table index
//     int getCurrentTable() const; // Function to get the current table index
//     void refreshTable(Category category); // Function to refresh the table view based on the category
//     void setupUI(Role role); // Function to set up UI based on the role
//     void changeWorkerScreen(Category category); // Function to change the worker screen based on the category
//     void hideAllUI(); // Function to hide all UI elements
//     void populateComboBox(QComboBox *comboBox, const QString &tableName, const QString &displayColumn, const QString &idColumn); // Helper function to populate combo boxes
//     void populateComboBoxWithRegion(QComboBox *comboBox, const QString &tableName, const QString &displayColumn, const QString &idColumn, int regionID); // Helper function to populate combo boxes with region filter
//     void refreshUsersTable(); // Function to refresh Users table
//     void refreshSheltersTable(); // Function to refresh Shelters table
//     void refreshBookingsTable(); // Function to refresh Bookings table
//     void refreshHurricanesTable(); // Function to refresh Hurricanes table
//     void refreshLocationsTable(); // Function to refresh Locations table
// };
// #endif // MAINWINDOW_H
