/* 
 * File:   Status.h
 * Author: Alex Kozlov <alexssource@gmail.com>
 *
 * Created on December 1, 2011, 1:59 PM
 */

#ifndef STATUS_H
#define	STATUS_H

#include <iostream>
#include <string>
#include "BaseRecord.h"
#include "SqlConnector.h"

using namespace std;

class Status: public BaseRecord
{
private:
    string name;
    
public:
    Status(SqlConnector* const);
    Status(SqlConnector* const, int);
    Status(const Status&);
    virtual ~Status();
    
    // Properties:
    string Name() const { return this->name; }
    void Name(string name) { this->name = name; }
    
    
    // Section for overrides methods
    
    // Oveerided methods
protected:
    virtual string GetSqlCreate() const;
    virtual string GetSqlUpdate() const;
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

#endif	/* STATUS_H */

