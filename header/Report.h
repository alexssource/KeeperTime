/* 
 * File:   Report.h
 * Author: Alex Kozlov <alexssource@gmail.com>
 *
 * Created on December 1, 2011, 12:48 PM
 */

#ifndef REPORT_H
#define	REPORT_H

#include <iostream>
#include <string>
#include "Task.h"
#include "Project.h"
#include "DateTime.h"

using namespace std;

class Report: public BaseRecord
{
private:
    Task* task;
    Project* project;
    string report;
    float hours;
    string tmpl;
    DateTime* created_at;

    void GetTemplate();
    
public:
    Report(SqlConnector* const);
    Report(SqlConnector* const, int);
    Report(const Report &);
    virtual ~Report();
    
    void ProcessingReport();
    
    // Properties:
    Task* GetTask() const { return this->task; }
    void SetTask(Task* task) { this->task = task; }
    Project* GetProject() const { return this->project; }
    void SetProject(Project* project) { this->project = project; }
    string GetReport() const { return this->report; }
    void SetReport(string report) { this->report = report; }
    float Hours() const { return this->hours; }
    void Hours(float hours) { this->hours = hours; }
    string Tmpl() const { return this->tmpl; }
    void Tmpl(string tmpl) { this->tmpl = tmpl; }
    DateTime* CreatedAt() const { return this->created_at; }
    void CreatedAt(DateTime* created) { this->created_at = created; }
    
    
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

#endif	/* REPORT_H */