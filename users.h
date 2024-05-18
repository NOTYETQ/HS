#ifndef USERS_H
#define USERS_H
#include "entity.h"

class Users
{
public:
    Users();
    ~Users();
    
    // setters
    int setUser_ID(int user_id);
    QString setSSN(const QString &ssn);
    QString setRole(const QString &role);
    QString setFirst_Name(const QString &first_name);
    QString setMiddle_Name(const QString &middle_name);
    QString setLast_Name(const QString &last_name);
    QString setAddress(const QString &address);
    QString setContact_Number(const QString &contact_number);
    bool setBlocked(bool blocked);
    QString setPassword(const QString &password);

    // getters
    int getUser_ID() const;
    QString getSSN() const;
    QString getRole() const;
    QString getFirst_Name() const;
    QString getMiddle_Name() const;
    QString getLast_Name() const;
    QString getAddress() const;
    QString getContact_Number() const;
    bool getBlocked() const;
    QString getPassword() const;

private:
    int User_ID;
    QString SSN;
    QString Role;
    QString First_Name;
    QString Middle_Name;
    QString Last_Name;
    QString Address;
    QString Contact_Number;
    bool Blocked;
    QString Password;
};

#endif // USERS_H