#ifndef SESSION_H
#define SESSION_H

#include "users.h"
#include "entitycrud.h"
#include "userscrud.h"

class Session
{
public:
    Session();
    ~Session();

    bool Login(const Users& user);
    bool Logout();
    bool getIsLoggedIn();
    bool setIsLoggedIn(bool loggedin);
    bool verifyCredentials(const QString &ssn, const QString &password);
    Users getCurrent_User();

private:
    Users Current_User;
    bool IsLoggedIn;
};

#endif // SESSION_H
