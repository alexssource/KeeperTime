/* 
 * File:   Team.h
 * Author: alex
 *
 * Created on December 18, 2011, 7:32 PM
 */

#ifndef TEAM_H
#define	TEAM_H

#include "BaseRecord.h"
#include "DateTime.h"


class Team: public BaseRecord
{
private:
    string name;
    DateTime* created_at;
    
public:
    Team(SqlConnector* const conn);
    Team(SqlConnector* const conn, int id);
    Team(const Team& orig);
    virtual ~Team();
    
    // Properties:
    string Name() const { return this->name; }
    void Name(string name) { this->name = name; }
    
    DateTime* CreatedAt() const { return this->created_at; }
    void CreatedAt(DateTime* created_at) { this->created_at = created_at; }
    void CreatedAt(int timestamp) { this->created_at = new DateTime(timestamp); }
    void CreatedAt(int year, int month, int day = 1, int hour = 0, int minute = 0, int seconds = 0) {
        this->created_at = new DateTime(year, month, day, hour, minute, seconds);
    }
    
    // Oveerided methods
protected:
    virtual string GetSqlCreate() const;
    virtual string GetSqlUpdate() const;
    
public:
    virtual bool Retrieve();
    virtual BaseRecord* RetrieveRecord(int id);
    virtual vector<BaseRecord *> RetrieveTableRecords(string where = "", string limit = "") const;
};

#endif	/* TEAM_H */

