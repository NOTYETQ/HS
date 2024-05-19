QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bookings.cpp \
    bookingscrud.cpp \
    databasemanager.cpp \
    entity.cpp \
    entitycrud.cpp \
    hurricanes.cpp \
    hurricanescrud.cpp \
    locations.cpp \
    locationscrud.cpp \
    main.cpp \
    mainwindow.cpp \
    session.cpp \
    shelters.cpp \
    shelterscrud.cpp \
    users.cpp \
    userscrud.cpp

HEADERS += \
    Errors.h \
    bookings.h \
    bookingscrud.h \
    databasemanager.h \
    entity.h \
    entitycrud.h \
    hurricanes.h \
    hurricanescrud.h \
    locations.h \
    locationscrud.h \
    mainwindow.h \
    session.h \
    shelters.h \
    shelterscrud.h \
    users.h \
    userscrud.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
