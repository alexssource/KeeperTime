/* 
 * File:   User.h
 * Author: Alex Kozlov <alexssource@gmail.com>
 *
 * Created on December 1, 2011, 11:02 AM
 */

#ifndef USER_H
#define	USER_H

#include "BaseRecord.h"
#include "DateTime.h"
#include "Group.h"
#include "Team.h"

using namespace std;

class User: public BaseRecord
{
private:
    string name;
    string surname;
    string login;
    string password;
    string email;
    float wage; // часовая тарифная ставка
    Group* group;
    Team* team;
    DateTime* created_at;
    
public:
    User(SqlConnector* const);
    User(SqlConnector* const, int);
    User(const User&);
    virtual ~User();
    
    // Properties:
    string Name() const { return this->name; }
    void Name(string name) { this->name = name; }
    string Surname() const { return this->surname; }
    void Surname(string surname) { this->surname = surname; }
    string Login() const { return this->login; }
    void Login(string login) { this->login = login; }
    string Password() const { return this->password; }
    void Password(string pass) { this->password = pass; }
    string Email() const { return this->email; }
    void Email(string email) { this->email = email; }
    float Wage() const { return this->wage; }
    void Wage(float w) { this->wage = w; }
    
    Group* GetGroup() const { return this->group; }
    void SetGroup(Group* group) { this->group = group; }
    void SetGroup(int group_id) { this->group = new Group(this->connector, group_id); }
    
    Team* GetTeam() const { return this->team; }
    void SetTeam(Team* team) { this->team = team; }
    void SetTeam(int team_id) { this->team = new Team(this->connector, team_id); }
    
    DateTime* CreatedAt() const { return this->created_at; }
    void CreatedAt(DateTime* created_at) { this->created_at = created_at; }
    void CreatedAt(int timestamp) { this->created_at = new DateTime(timestamp); }
    void CreatedAt(int year, int month, int day = 1, int hour = 0, int minute = 0, int seconds = 0) {
        this->created_at = new DateTime(year, month, day, hour, minute, seconds);
    }
    
    
    // Section for overrides methods
    
    // Oveerided methods
protected:
    virtual string GetSqlCreate() const;
    virtual string GetSqlUpdate() const;
    virtual void InitializeRecord();
    virtual bool IsSet() const;
    
public:
    virtual bool Retrieve();
    virtual BaseRecord* RetrieveRecord(int id);
    
    /**
     * Retrieves the records from current table with various condition and limit
     * @param where - the string of condition
     * @param limit - the string of limit
     * @return vector&lt;BaseRecord *&rt; - the vector of table rows
     */
    virtual vector<BaseRecord *> RetrieveTableRecords(string where = "", string limit = "") const;
};

#endif	/* USER_H */