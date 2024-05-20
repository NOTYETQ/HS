#include "users.h"

Users::Users() {
    setAddress(NULL);
    setBlocked(NULL);
    setContact_Number(NULL);
    setFirst_Name(NULL);
    setLast_Name(NULL);
    setMiddle_Name(NULL);
    setPassword(NULL);
    setRole(NULL);
    setSSN(NULL);
    setUser_ID(0);
}

Users::Users(int user_id){
    setUser_ID(user_id);
    setAddress(NULL);
    setBlocked(NULL);
    setContact_Number(NULL);
    setFirst_Name(NULL);
    setLast_Name(NULL);
    setMiddle_Name(NULL);
    setPassword(NULL);
    setRole(NULL);
    setSSN(NULL);
}

Users::Users(const QString &ssn, const QString &password){
    setUser_ID(NULL);
    setAddress(NULL);
    setBlocked(NULL);
    setContact_Number(NULL);
    setFirst_Name(NULL);
    setLast_Name(NULL);
    setMiddle_Name(NULL);
    setPassword(password);
    setRole(NULL);
    setSSN(ssn);
}

Users::~Users() {
}

// setters
void Users::setUser_ID(int user_id){
    User_ID = user_id;
}
void Users::setSSN(const QString &ssn){
    SSN = ssn;
}
void Users::setRole(const QString &role){
    Role = role;
}
void Users::setFirst_Name(const QString &first_name){
    First_Name = first_name;
}
void Users::setMiddle_Name(const QString &middle_name){
    Middle_Name = middle_name;
}
void Users::setLast_Name(const QString &last_name){
    Last_Name = last_name;
}
void Users::setAddress(const QString &address){
    Address = address;
}
void Users::setContact_Number(const QString &contact_number){
    Contact_Number = contact_number;
}
void Users::setBlocked(bool blocked){
    Blocked = blocked;
}
void Users::setPassword(const QString &password){
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
    return Contact_Number;
}
bool Users::getBlocked() const{
    return Blocked;
}
QString Users::getPassword() const{
    return Password;
}
