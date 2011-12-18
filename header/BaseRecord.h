/* 
 * File:   BaseRecord.h
 * Author: Alex Kozlov <alexssource@gmail.com>
 *
 * Created on November 30, 2011, 11:37 PM
 */

#ifndef BASERECORD_H
#define	BASERECORD_H

#include <stdlib.h>
#include <string>
#include <vector>
#include "SqlConnector.h"
#include "NumberToStringConverter.h"

using namespace std;

class BaseRecord
{
protected:
    
    /**
     * The identifier of record
     * This field is readonly
     */
    int id;
    
    /**
     * Name of table for current record
     */
    string table;
    
    /**
     * The pointer to sql-connector for calling to database
     */
    SqlConnector* const connector;      // константный указатель на не константные данные
    
    /**
     * Initialize the begins parameters
     * @param table - the name of table
     * @param id - record id
     */
    void Initialize(string table, int id = 0)
    {
        this->table = table;
        this->id = id;
    }
    
    
    /**
     * Created the new record and assign them the unique identifier
     * @return bool result
     */
    virtual bool Create()
    {
        if(this->CreateRecord()) {
            this->id = this->connector->GetLastInsertedId();
            return true;
        }
        else return false;
    }
    

    /**
     * Updates the current record by its identifier
     * @param id - the identifier of record
     * @return result - the result of update operation
     */
    virtual bool UpdateRecord() const { };
    
    
    /**
     * Creates a new record
     * @return <bool> res - the result of insert record process
     */
    virtual bool CreateRecord() const { };
    
    
    /**
     * Delete the current record from database
     * @return <bool> res
     */
    virtual bool DeleteRecord() const { }
    
    /**
     * Retrieve the record from database by it's id
     * All fields, which will be find in database must contain current object
     */
    virtual bool Retrieve() { };
    
    
    /**
     * Obtaining records from an arbitrary identifier
     * @param id - the identifier of record
     * @return BaseRecord* - pointer to result object
     */
    virtual BaseRecord* RetrieveRecord(int id) { };
    
    
    /**
     * Reset all field to their begin status
     */
    virtual void Reset() {
        this->table = "";
        this->id = 0;
    }
    
    
    /**
     * Used in the derived class for in begin initialization
     * (called in current's class constructor)
     */
    virtual void InitializeRecord() { };
    
public:
    BaseRecord(SqlConnector* const conn, string table): connector(conn) {
        this->Initialize(table);
        this->InitializeRecord();
    }
    
    BaseRecord(SqlConnector* const conn, string table, int id): connector(conn) {
        this->Initialize(table, id);
        this->InitializeRecord();
        this->Retrieve();
    }
    
    virtual ~BaseRecord() { }
    
    /**
     * Returns the identifier of current record (0 if isn't set)
     * @return id - identifier of record
     */
    int GetId() const { return this->id; }
    
    
    /**
     * Save or update the current record to database
     * @param id - the identifier of record (default is 0 for create a new record)
     * @return result - true if result is success
     */
    virtual bool Save()
    {
        return (this->id == 0) ? this->Create() : this->UpdateRecord();
    }
    
    
    /**
     * Delete the current record
     * Need to override the method DeleteRecord in the derived type
     * @return <bool> result
     */
    virtual bool Delete()
    {
        bool result;
        
        result = this->DeleteRecord();
        this->Reset();
        return result;
    }
    
    /**
     * Retrieves the rows from current table with limit
     * @param where - the string of condition
     * @param limit - the string of limit
     * @return vector<MYSQL_ROW> - the vector of table rows
     */
    virtual vector<string *> RetrieveTableRows(string where = "", string limit = "") const ;
    
    
    /**
     * Retrieves the records from current table with various condition and limit
     * @param where - the string of condition
     * @param limit - the string of limit
     * @return vector&lt;BaseRecord *&rt; - the vector of table rows
     */
    virtual vector<BaseRecord *> RetrieveTableRecords(string where = "", string limit = "") const { };
};

#endif	/* BASERECORD_H */