/* 
 * File:   BaseRecord.h
 * Author: Alex Kozlov <alexssource@gmail.com>
 *
 * Created on November 30, 2011, 11:37 PM
 */

#ifndef BASERECORD_H
#define	BASERECORD_H

#include "SqlConnector.h"

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
    
    
    void Initialize(string table, int id = 0)
    {
        this->table = table;
        this->id = id;
    }
    
public:
    BaseRecord(string table) { this->Initialize(table); }
    BaseRecord(string table, int id) { this->Initialize(table, id); }
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
    virtual bool Save(const SqlConnector& conn)
    {
        return (this->id == 0) ? this->CreateRecord(conn) : this->UpdateRecord(conn);
    }
    
    
    /**
     * Retrieve the record from database by it's id
     * @param id - the identifier of record
     * @return record - finding record
     */
    virtual BaseRecord Retrieve(SqlConnector conn, int id);
    
    
    /**
     * Updates the current record by its identifier
     * @param id - the identifier of record
     * @return result - the result of update operation
     */
    virtual bool UpdateRecord(SqlConnector conn);
    
    
    /**
     * Creates a new record
     * @return <int> id - the identifier of inserted record
     */
    virtual int CreateRecord(SqlConnector conn);
};

#endif	/* BASERECORD_H */