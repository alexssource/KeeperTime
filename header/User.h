/* 
 * File:   User.h
 * Author: Alex Kozlov <alexssource@gmail.com>
 *
 * Created on December 1, 2011, 11:02 AM
 */

#ifndef USER_H
#define	USER_H

#include <iostream>
#include <string>
#include "BaseRecord.h"

using namespace std;

class User: public BaseRecord
{
private:
    string name;
    string surname;
    string login;
    string password;
    string email;
    Group group;
    Team team;
    DateTime created_at;
    
public:
    User();
    User(int id);
    virtual ~User();
    virtual User Retrieve(SqlConnector conn, int id);
    virtual bool UpdateRecord(SqlConnector conn);
    virtual bool CreateRecord(SqlConnector conn);
    bool CompareTo(const User& rhs);
    
    // Properties:
    string GetName() { return this->name; }
    void SetName(string name) { this->name = name; }
    string GetSurname() { return this->surname; }
    void SetSurname(string surname) { this->surname = surname; }
    string GetLogin() { return this->login; }
    void SetLogin(string login) { this->login = login; }
    string GetPassword() { return this->password; }
    void SetPassword(string pass) { this->password = pass; }
    string GetEmail() { return this->email; }
    void SetEmail(string email) { this->email = email; }
    Group GetGroup() { return this->group; }
    void SetGroup(Group group) { this->group = group; }
    Team GetTeam() { return this->team; }
    void SetTeam(Team team) { this->team = team; }
    DateTime GetCreatedAt() { return this->created_at; }
    void SetCreatedAt(DateTime created_at) { this->created_at = created_at; }
};

#endif	/* USER_H */

