#ifndef SESSION_H
#define SESSION_H

#include "users.h"
#include "entitycrud.h"

class Session
{
public:
    Session();
    ~Session();

    bool Login(const Users& user);
    bool Logout();
    bool getIsLoggedIn();
    bool setIsLoggedIn(bool loggedin);
    Users getCurrent_User();
    bool verifyCredentials(const Users& loginAttempt, Users& authenticatedUser);

private:
    Users Current_User;
    bool IsLoggedIn;
};

#endif // SESSION_H
