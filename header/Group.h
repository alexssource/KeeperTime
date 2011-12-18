/* 
 * File:   Group.h
 * Author: alex
 *
 * Created on December 17, 2011, 3:34 PM
 */

#ifndef GROUP_H
#define	GROUP_H

#include "BaseRecord.h"

using namespace std;

class Group: public BaseRecord
{
private:
    // Fields and initialize methods
    string name;
    bool is_manager;
    bool is_admin;
    
public:
    // Constructors and Destructors
    Group(SqlConnector* const conn);
    Group(SqlConnector* const conn, int id);
    Group(const Group& orig);
    virtual ~Group();
    
    
    // Properties
    string Name() const { return this->name; }
    void Name(string name) { this->name = name; }
    bool IsManager() const { return this->is_manager; }
    void IsManager(bool is_manager) { this->is_manager = is_manager; }
    bool IsAdmin() const { return this->is_admin; }
    void IsAdmin(bool is_admin) { this->is_admin = is_admin; }
    
    
    
    // Section for overrides methods
    
protected:
    virtual string GetSqlCreate() const;
    virtual string GetSqlUpdate() const;
    virtual string GetSqlDelete() const;
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

#endif	/* GROUP_H */
