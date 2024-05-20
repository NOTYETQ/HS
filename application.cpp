#include "application.h"
#include "ui_application.h"

Application::Application(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Application)
{
    ui->setupUi(this);
    ui->SW_Authentication->setCurrentIndex(0);
    connect(ui->PB_Login_Login, &QPushButton::clicked, this, &Application::loginClicked);
    connect(ui->PB_Login_SignUp, &QPushButton::clicked, this, &Application::signUpClicked);
    connect(ui->PB_SignUp_Confirm, &QPushButton::clicked, this, &Application::signUp);
    connect(ui->PB_SignUp_Cancel, &QPushButton::clicked, this, &Application::cancelSignUp);
    connect(ui->PB_Header_EditProfile, &QPushButton::clicked, this, &Application::editProfileClicked);
    connect(ui->PB_Header_Logout, &QPushButton::clicked, this, &Application::logout);
    connect(ui->PB_UR_EP_Cancel, &QPushButton::clicked, this, &Application::editProfileCancelled);
    connect(ui->PB_UR_EP_Okay, &QPushButton::clicked, this, &Application::editProfileConfirm);
    connect(ui->PB_Workers_Screen_Bookings, &QPushButton::clicked, this, &Application::onBookingsButtonClicked);
    connect(ui->PB_Workers_Screen_Hurricanes, &QPushButton::clicked, this, &Application::onHurricanesButtonClicked);
    connect(ui->PB_Workers_Screen_Users, &QPushButton::clicked, this, &Application::onUsersButtonClicked);
    connect(ui->PB_Workers_Screen_Location, &QPushButton::clicked, this, &Application::onLocationsButtonClicked);
    connect(ui->PB_Workers_Screen_Shelters, &QPushButton::clicked, this, &Application::onSheltersButtonClicked);

}

Application::~Application()
{
    delete ui;
}

// login slot
void Application::loginClicked() {
    try {
        Users loginAttempt(ui->LE_Login_SSN->text(), ui->LE_Login_Password->text());
        if (session.Login(loginAttempt)) {
            ui->SW_Authentication->setCurrentIndex(1);
            QString UserName = session.getCurrent_User().getFirst_Name() + " " + session.getCurrent_User().getMiddle_Name() + " " + session.getCurrent_User().getLast_Name();
            ui->L_Header_CurrentUserTitle->setText(UserName);
            CRUD_Users.setRole(session.getCurrent_User().getRole());
            showui();
            ui->LE_Login_Password->clear();
            ui->LE_Login_SSN->clear();
            QMessageBox::information(this, "Login Success", UserName + " has logged in!", QMessageBox::Close);
        }
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", QString(e.what()), QMessageBox::Cancel);
        ui->LE_Login_Password->clear();
        ui->LE_Login_SSN->clear();
    }
}

// for the categories
Application::Categories Application::getCategory() const {
    return category;
}

void Application::setCategory(Application::Categories newCategory) {
    category = newCategory;
}

// signupclickedslot
void Application::signUpClicked() {
    ui->LE_Login_Password->clear();
    ui->LE_Login_SSN->clear();
    ui->SW_Authentication->setCurrentIndex(2);
}

// register slot;
void Application::signUp() {
    try {
        Users signupUser;
        QString address = ui->LE_SignUp_Address->text();
        QString contactNumber = ui->LE_SignUp_ContactNumber->text();
        QString firstName = ui->LE_SignUp_FName->text();
        QString lastName = ui->LE_SignUp_LName->text();
        QString middleName = ui->LE_SignUp_MName->text();
        QString password = ui->LE_SignUp_Password->text();
        QString ssn = ui->LE_SignUp_SSN->text();
        QString passwordConfirm = ui->LE_SignUp_PasswordConfirm->text();

        signupUser.setAddress(address);
        signupUser.setContact_Number(contactNumber);
        signupUser.setFirst_Name(firstName);
        signupUser.setLast_Name(lastName);
        signupUser.setMiddle_Name(middleName);
        signupUser.setPassword(password);
        signupUser.setSSN(ssn);

        if(CRUD_Users.userExists(ssn)) {
            throw;
        }

        if (!CRUD_Users.passwordMatch(password, passwordConfirm)){
            throw;
        }
        if (!CRUD_Users.add(signupUser)) {
            throw;
        }
        QMessageBox::information(this, "User Registered!", "User Registered!", QMessageBox::Cancel);

        // Clear line edits
        ui->LE_SignUp_Address->clear();
        ui->LE_SignUp_ContactNumber->clear();
        ui->LE_SignUp_FName->clear();
        ui->LE_SignUp_LName->clear();
        ui->LE_SignUp_MName->clear();
        ui->LE_SignUp_Password->clear();
        ui->LE_SignUp_PasswordConfirm->clear();
        ui->LE_SignUp_SSN->clear();
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", QString(e.what()), QMessageBox::Cancel);

        ui->LE_SignUp_Address->clear();
        ui->LE_SignUp_ContactNumber->clear();
        ui->LE_SignUp_FName->clear();
        ui->LE_SignUp_LName->clear();
        ui->LE_SignUp_MName->clear();
        ui->LE_SignUp_Password->clear();
        ui->LE_SignUp_PasswordConfirm->clear();
        ui->LE_SignUp_SSN->clear();
    }
}

// cancel signupslot;

void Application::cancelSignUp() {
    ui->SW_Authentication->setCurrentIndex(0);
    ui->LE_SignUp_Address->clear();
    ui->LE_SignUp_ContactNumber->clear();
    ui->LE_SignUp_FName->clear();
    ui->LE_SignUp_LName->clear();
    ui->LE_SignUp_MName->clear();
    ui->LE_SignUp_Password->clear();
    ui->LE_SignUp_PasswordConfirm->clear();
    ui->LE_SignUp_SSN->clear();
}


void Application::logout() {
    session.Logout();
    ui->SW_Authentication->setCurrentIndex(0);
}

void Application::editProfileClicked() {
    ui->SW_RoleScreenChanger->setCurrentIndex(0);
    // Retrieve the values from the session.getCurrent_User() object
    QString address = session.getCurrent_User().getAddress();
    QString contactNumber = session.getCurrent_User().getContact_Number();
    QString firstName = session.getCurrent_User().getFirst_Name();
    QString lastName = session.getCurrent_User().getLast_Name();
    QString middleName = session.getCurrent_User().getMiddle_Name();

    // Assign the retrieved values to the corresponding line edits
    ui->LE_EditProfile_Address->setText(address);
    ui->LE_EditProfile_ContactNumber->setText(contactNumber);
    ui->LE_EditProfile_FName->setText(firstName);
    ui->LE_EditProfile_LName->setText(lastName);
    ui->LE_EditProfile_MName->setText(middleName);
}

void Application::editProfileConfirm() {
    try {
        // Retrieve the values from the line edits after they have been edited
        QString updatedAddress = ui->LE_EditProfile_Address->text();
        QString updatedContactNumber = ui->LE_EditProfile_ContactNumber->text();
        QString updatedFirstName = ui->LE_EditProfile_FName->text();
        QString updatedLastName = ui->LE_EditProfile_LName->text();
        QString updatedMiddleName = ui->LE_EditProfile_MName->text();
        QString newPassword = ui->LE_EditProfile_NewPassword->text();
        QString newPasswordConfirm = ui->LE_EditProfile_NewPasswordConfirm->text();
        QString oldPasswordConfirm = ui->LE_EditProfile_OldPassword->text();

        // Check if the old password is provided when attempting to change the password
        if (!newPassword.isEmpty() || !newPasswordConfirm.isEmpty()) {
            if (oldPasswordConfirm.isEmpty()) {
                throw std::runtime_error("Old password must be provided to change the password.");
            }

            QString oldPassword = session.getCurrent_User().getPassword();

            // Check if old password matches
            if (!CRUD_Users.passwordMatch(oldPasswordConfirm, oldPassword)) {
                throw std::runtime_error("Old password does not match.");
            }

            // Check if new password and its confirmation match
            if (!CRUD_Users.passwordMatch(newPassword, newPasswordConfirm)) {
                throw std::runtime_error("New passwords do not match.");
            }

            // Set the new password
            session.getCurrent_User().setPassword(newPassword);
        }

        // Assuming session.getCurrent_User() returns a reference to a Users object
        // Set the retrieved values into the session.getCurrent_User() object
        session.getCurrent_User().setAddress(updatedAddress);
        session.getCurrent_User().setContact_Number(updatedContactNumber);
        session.getCurrent_User().setFirst_Name(updatedFirstName);
        session.getCurrent_User().setLast_Name(updatedLastName);
        session.getCurrent_User().setMiddle_Name(updatedMiddleName);

        // Update the user information in the database
        CRUD_Users.edit(session.getCurrent_User());

        // Show success message
        QMessageBox::information(this, "Success", "Profile updated successfully", QMessageBox::Ok);
    } catch (const std::runtime_error& e) {
        // Show error message for runtime errors
        QMessageBox::critical(this, "Error", e.what(), QMessageBox::Ok);
    } catch (const std::exception& e) {
        // Show error message for general exceptions
        QMessageBox::critical(this, "Error", e.what(), QMessageBox::Ok);
    } catch (...) {
        // Catch any other exceptions
        QMessageBox::critical(this, "Error", "An unexpected error occurred", QMessageBox::Ok);
    }
}

void Application::editProfileCancelled() {
    if (CRUD_Users.getRole() == Role::Bookie){
        ui->SW_RoleScreenChanger->setCurrentIndex(1);
    } else {
        ui->SW_RoleScreenChanger->setCurrentIndex(2);
    }
    ui->LE_EditProfile_Address->clear();
    ui->LE_EditProfile_ContactNumber->clear();
    ui->LE_EditProfile_FName->clear();
    ui->LE_EditProfile_LName->clear();
    ui->LE_EditProfile_MName->clear();
    ui->LE_EditProfile_NewPassword->clear();
    ui->LE_EditProfile_NewPasswordConfirm->clear();
    ui->LE_EditProfile_OldPassword->clear();
}

void Application::showui() {
    switch (CRUD_Users.getRole()) {
    case Role::Administrator:
        ui->SW_RoleScreenChanger->setCurrentIndex(2);
        ui->PB_Workers_Screen_Location->show();
        ui->PB_Workers_Delete->show();

        break;
    case Role::Employee:
        ui->SW_RoleScreenChanger->setCurrentIndex(2);
        ui->PB_Workers_Screen_Location->hide();
        ui->PB_Workers_Delete->hide();
        break;
    case Role::Bookie:
        ui->SW_RoleScreenChanger->setCurrentIndex(1);
        break;
    }
}

void Application::selectworkerscreen() {
    try{
        ui->SW_Workers_Screen->setCurrentIndex(0);
        QSqlQueryModel *model = nullptr;
        switch (getCategory()) {
        case Application::Categories::Bookings:
            CRUD_Booking.viewTable();
            break;
        case Application::Categories::Hurricanes:
            CRUD_Hurricane.viewTable();
            break;
        case Application::Categories::Users:
            CRUD_Users.viewTable();
            break;
        case Application::Categories::Locations:
            CRUD_Location.viewTable();
            break;
        case Application::Categories::Shelters:
            CRUD_Shelters.viewTable();
            break;
        default:
            // Handle default case
            break;
        }
        if (model) {
            ui->TV_Workers->setModel(model);
            ui->TV_Workers->resizeColumnsToContents();
        } else {
            throw std::runtime_error("Failed to create model");
        }
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", e.what());
    }
}

void Application::handleAddAction() {
    switch (category) {
    case Categories::Bookings:
        ui->SW_Workers_Screen->setCurrentIndex(1);
        break;
    case Categories::Hurricanes:
        ui->SW_Workers_Screen->setCurrentIndex(2);
        ui->LE_Worker_Hurricane_Name->clear();
        break;
    case Categories::Users:
        ui->SW_Workers_Screen->setCurrentIndex(5);
        ui->LE_Worker_Users_Address->clear();
        ui->LE_Worker_Users_CpntactNumber->clear();
        ui->LE_Worker_Users_FName->clear();
        ui->LE_Worker_Users_LName->clear();
        ui->LE_Worker_Users_SSN->clear();
        ui->LE_Worker_Users_SSN->setDisabled(true);
        ui->LE_Worker_Users_Password->clear();
        // ...
        break;
    case Categories::Locations:
        ui->SW_Workers_Screen->setCurrentIndex(3);
        ui->LE_Workers_Locations_Location->clear();
        // ...
        break;
    case Categories::Shelters:
        ui->SW_Workers_Screen->setCurrentIndex(4);
        ui->LE_Workers_Shelters_Latitude->clear();
        ui->LE_Workers_Shelters_Longitude->clear();
        break;
    default:
        // Handle default category
        throw std::invalid_argument("Invalid category");
    }
}

void Application::handleDeleteAction() {
    switch (category) {
    case Categories::Bookings:
            break;
    case Categories::Hurricanes:
        // Handle Add action for Hurricanes
        // ...
        break;
    case Categories::Users:
        // Handle Add action for Users
        // ...
        break;
    case Categories::Locations:
        // Handle Add action for Locations
        // ...
        break;
    case Categories::Shelters:
        // Handle Add action for Shelters
        // ...
        break;
    default:
        // Handle default category
        throw std::invalid_argument("Invalid category");
    }
}

void Application::handleEditAction() {
    // get the first row




    switch (category) {
    case Categories::Bookings:
        // call the objcet then the function
            break;
    case Categories::Hurricanes:
        // Handle Add action for Hurricanes
        // ...
        break;
    case Categories::Users:
        // Handle Add action for Users
        // ...
        break;
    case Categories::Locations:
        // Handle Add action for Locations
        // ...
        break;
    case Categories::Shelters:
        // Handle Add action for Shelters
        // ...
        break;
    default:
        // Handle default category
        throw std::invalid_argument("Invalid category");
    }
}


void Application::onBookingsButtonClicked() {
    setCategory(Categories::Bookings);
    selectworkerscreen();
}

void Application::onHurricanesButtonClicked() {
    setCategory(Categories::Hurricanes);
    selectworkerscreen();
}

void Application::onUsersButtonClicked() {
    setCategory(Categories::Users);
    selectworkerscreen();
}

void Application::onLocationsButtonClicked() {
    setCategory(Categories::Locations);
    selectworkerscreen();
}

void Application::onSheltersButtonClicked() {
    setCategory(Categories::Shelters);
    selectworkerscreen();
}

void Application::on_PB_Workers_Add_clicked()
{
    handleAddAction();
}

