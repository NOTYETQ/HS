
#include <QApplication>
#include "application.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();
    Application app;
    app.show();
    a.exec();
}
