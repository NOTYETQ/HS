#include "users.h"

Users::Users() {}

Users::~Users(){}

// setters
int Users::setUser_ID(int user_id){
    User_ID = user_id;
}
QString Users::setSSN(const QString &ssn){
    SSN = ssn;
}
QString Users::setRole(const QString &role){
    Role = role;
}
QString Users::etFirst_Name(const QString &first_name){
    First_Name = first_name
}
QString Users::setMiddle_Name(const QString &middle_name){
    Middle_Name = middle_name;
}
QString Users::setLast_Name(const QString &last_name){
    Last_Name = last_name;
}
QString Users::setAddress(const QString &address){
    Address = address;
}
QString Users::setContact_Number(const QString &contact_number){
    Contact_Number = contact_number;
}
bool Users::setBlocked(bool blocked){}
QString Users::setPassword(const QString &password){
    Password = password;
}

// getters
int Users::getUser_ID() const{
    return User_ID;
}
QString Users::getSSN() const{
    return SSN;
}
QString Users::getRole() const{
    return Role;
}
QString Users::getFirst_Name() const{
    return First_Name;
}
QString Users::getMiddle_Name() const{
    return Middle_Name;
}
QString Users::getLast_Name() const{
    return Last_Name;
}
QString Users::getAddress() const{
    return Address;
}
QString Users::getContact_Number() const{
    return getContact_Number;
}
bool Users::getBlocked() const{
    return Blocked;
}
QString Users::getPassword() const{
    return Password;
}
