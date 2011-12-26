/* 
 * File:   Task.h
 * Author: Alex Kozlov <alexssource@gmail.com>
 *
 * Created on December 1, 2011, 2:31 PM
 */

#ifndef TASK_H
#define	TASK_H

#include <iostream>
#include <string>
#include "BaseRecord.h"
#include "SqlConnector.h"
#include "Project.h"
#include "User.h"
#include "Status.h"
#include "DateTime.h"

using namespace std;

class Task: public BaseRecord
{
private:
    string name;
    string title;
    string description;
    int priority;
    float timming_plan;
    Project* project;
    User* user;
    Status* status;
    DateTime* created_at;
    
public:
    Task(SqlConnector* const);
    Task(SqlConnector* const, int);
    Task(const Task &);
    virtual ~Task();
    
    // Properties:
    string Name() const { return this->name; }
    void Name(string name) { this->name = name; }
    string Title() const { return this->title; }
    void Title(string title) { this->title = title; }
    string Description() const { return this->description; }
    void Description(string description) { this->description = description; }
    float TimmingPlan() const { return this->timming_plan; }
    void TimmingPlan(float tp) { this->timming_plan = tp; }
    Project* GetProject() const { return this->project; }
    void SetProject(Project* project) { this->project = project; }
    void SetProject(int pid) { this->project = new Project(this->connector, pid); }
    User* GetUser() const { return this->user; }
    void SetUser(User* user) { this->user = user; }
    void SetUser(int uid) { this->user = new User(this->connector, uid); }
    Status* GetStatus() const { return this->status; }
    void SetStatus(Status* status) { this->status = status; }
    void SetStatus(int sid) { this->status = new Status(this->connector, sid); }
    int Priority() const { return this->priority; }
    void Priority(int p) { this->priority = p; }
    DateTime* CreatedAt() const { return this->created_at; }
    void CreatedAt(DateTime* ca) { this->created_at = ca; }
    
    
    
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

#endif	/* TASK_H */