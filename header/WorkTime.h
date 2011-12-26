/* 
 * File:   WorkTime.h
 * Author: Alex Kozlov <alexssource@gmail.com>
 *
 * Created on December 5, 2011, 12:05 PM
 */

#ifndef WORKTIME_H
#define	WORKTIME_H

#include <string>
#include "BaseRecord.h"
#include "DateTime.h"
#include "User.h"

using namespace std;

class WorkTime: public BaseRecord
{
private:
    DateTime* day;
    float hours;
    User* user;
    
public:
    WorkTime(SqlConnector* const);
    WorkTime(SqlConnector* const, int);
    WorkTime(const WorkTime&);
    virtual ~WorkTime();
    
    void AddTodayTime(float delta = 0.016);
    
    // Properties:
    DateTime* Day() const { return this->day; }
    void Day(DateTime* d) { this->day = d; }
    float Hours() const { return this->hours; }
    void Hours(float h) { this->hours = h; }
    User* GetUser() const { return this->user; }
    void SetUser(User* u) { this->user = u; }
    void SetUser(int uid) { this->user = new User(this->connector, uid); }
    
    
    // Override methods
protected:
    virtual string GetSqlCreate() const;
    virtual string GetSqlUpdate() const;
    virtual void InitializeRecord();
    
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
    
    virtual bool IsSet() const;
};

#endif	/* WORKTIME_H */

