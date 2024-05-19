#ifndef USERS_H
#define USERS_H

#include "entity.h"

class Users : public Entity {
public:
    Users();
    ~Users();

    void setUser_ID(int user_id);
    void setSSN(const QString &ssn);
    void setRole(const QString &role);
    void setFirst_Name(const QString &first_name);
    void setMiddle_Name(const QString &middle_name);
    void setLast_Name(const QString &last_name);
    void setAddress(const QString &address);
    void setContact_Number(const QString &contact_number);
    void setBlocked(bool blocked);
    void setPassword(const QString &password);

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
