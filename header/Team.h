/* 
 * File:   Team.h
 * Author: alex
 *
 * Created on December 18, 2011, 7:32 PM
 */

#ifndef TEAM_H
#define	TEAM_H

#include "BaseRecord.h"

class Team: public BaseRecord
{
private:
    string name;
    User* manager;
    DateTime created_at;
    
public:
    Team(SqlConnector* const conn);
    Team(SqlConnector* const conn, int id);
    Team(const Team& orig);
    virtual ~Team();
    
    // Properties:
    string Name() const { return this->name; }
    void Name(string name) { this->name = name; }
    
    User* Manager() const { return this->manager; }
    int Manager() const { std::cout << "Получить id юзера в Team.h: 31" << endl; return 1; }
    void Manager(User* manager) { this->manager = manager; }
    void Manager(int manager_id) { std::cout << "Получить объект юзера в Team.h: 33" << endl; }
    
    DateTime CreatedAt() const { return this->created_at; }
    void CreatedAt(DateTime created_at) { this->created_at = created_at; }
    void CreatedAt(string created_at) { std::cout << "Сделать преобразование из string в DateTime в Team.h: 37"; }
    
    
    // Oveerided methods
protected:
    virtual string GetSqlCreate() const;
    virtual string GetSqlUpdate() const;
    virtual void InitializeRecord();
    
public:
    virtual bool Retrieve();
    virtual BaseRecord* RetrieveRecord(int id);
    virtual vector<BaseRecord *> RetrieveTableRecords(string where = "", string limit = "") const;
};

#endif	/* TEAM_H */

