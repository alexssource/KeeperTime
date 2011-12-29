/* 
 * File:   Preject.h
 * Author: Alex Kozlov <alexssource@gmail.com>
 *
 * Created on December 1, 2011, 2:50 PM
 */

#ifndef PROJECT_H
#define	PROJECT_H

#include <iostream>
#include <string>
#include "BaseRecord.h"
#include "Team.h"
#include "Status.h"
#include "DateTime.h"

using namespace std;

class Project: public BaseRecord
{
private:
    string name;
    string description;
    float timming_plan;
    int priority;
    Team* team;
    Status* status;
    DateTime* created_at;
    DateTime* expired_at;
    DateTime* deadline;
    
public:
    Project(SqlConnector* const);
    Project(SqlConnector* const, int);
    Project(const Project &);
    virtual ~Project();
    
    // Properties:
    string Name() const { return this->name; }
    void Name(string name) { this->name = name; }
    string Description() const { return this->description; }
    void Description(string desc) { this->description = desc; }
    Team* GetTeam() const { return this->team; }
    void SetTeam(Team* team) { this->team = team; }
    float TimmingPlan() const { return this->timming_plan; }
    void TimmingPlan(float tp) { this->timming_plan = tp; }
    Status* GetStatus() const { return this->status; }
    void SetStatus(Status* s) { this->status = s; }
    int Priority() const { return this->priority; }
    void Priority(int p) { this->priority = p; }
    DateTime* CreatedAt() const { return this->created_at; }
    void CreatedAt(DateTime* ca) { this->created_at = ca; }
    DateTime* ExpiredAt() const { return this->expired_at; }
    void ExpiredAt(DateTime* ea) { this->expired_at = ea; }
    DateTime* Deadline() const { return this->deadline; }
    void Deadline(DateTime* dl) { this->deadline = dl; }
    
    
    // Oveerided methods
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
};

#endif	/* PROJECT_H */