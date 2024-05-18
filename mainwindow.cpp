#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QDate>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Get the current date
            QDate currentDate = QDate::currentDate();
    QString dateString = currentDate.toString("dd-MM-yyyy");

    // Set to label
    ui->L_Header_DateTitle->setText("Current Date: " + dateString);

    //get current time
    QTime currentTime = QTime::currentTime();
    QString timeString = currentTime.toString("hh:mm:ss");

    //set to label
    ui->L_Header_TimeTitle->setText("Current Time: " + timeString);

}
MainWindow::~MainWindow()
{
    delete ui;
}
