/* 
 * File:   BaseRecord.h
 * Author: Alex Kozlov <alexssource@gmail.com>
 *
 * Created on November 30, 2011, 11:37 PM
 */

#ifndef BASERECORD_H
#define	BASERECORD_H

#include "SqlConnector.h"
#include <vector>

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
    const SqlConnector* const connector;
    
    /**
     * Initialize the begins parameters
     * @param table - the name of table
     * @param id - record id
     */
    void Initialize(const SqlConnector* const conn, string table, int id = 0)
    {
        this->connector = conn;
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
    virtual bool UpdateRecord() = 0;
    
    
    /**
     * Creates a new record
     * @return <int> id - the identifier of inserted record
     */
    virtual int CreateRecord() = 0;
    
    
    
    /**
     * Retrieves the rows from current table with limit
     * @param where - the string of condition
     * @param limit - the string of limit
     * @return vector<MYSQL_ROW> - the vector of table rows
     */
    virtual vector<MYSQL_ROW> RetrieveTableRows(string where = "", string limit = "");
    
public:
    BaseRecord(const SqlConnector* const conn, string table) { this->Initialize(conn, table); }
    BaseRecord(const SqlConnector* const conn, string table, int id) { this->Initialize(conn, table, id); }
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
     * Retrieve the record from database by it's id
     * @param id - the identifier of record
     * @return record - finding record
     */
    virtual BaseRecord Retrieve(int id);
};

#endif	/* BASERECORD_H */