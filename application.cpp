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
        signupUser.setAddress(ui->LE_SignUp_Address->text());
        signupUser.setContact_Number(ui->LE_SignUp_ContactNumber->text());
        signupUser.setFirst_Name(ui->LE_SignUp_FName->text());
        signupUser.setLast_Name(ui->LE_SignUp_LName->text());
        signupUser.setMiddle_Name(ui->LE_SignUp_MName->text());
        signupUser.setPassword(ui->LE_SignUp_Password->text());
        signupUser.setSSN(ui->LE_SignUp_SSN->text());

        if(CRUD_Users.userExists(ui->LE_SignUp_SSN->text())) {
            throw;
        }

        if (!CRUD_Users.passwordMatch(ui->LE_SignUp_Password->text(), ui->LE_SignUp_PasswordConfirm->text())){
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

// setuploggedinuser;
