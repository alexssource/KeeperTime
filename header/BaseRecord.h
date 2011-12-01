/* 
 * File:   BaseRecord.h
 * Author: Alex Kozlov <alexssource@gmail.com>
 *
 * Created on November 30, 2011, 11:37 PM
 */

#ifndef BASERECORD_H
#define	BASERECORD_H

class BaseRecord
{
protected:
    
    /**
     * The identifier of record
     * This field is readonly
     */
    int id;
    
public:
    BaseRecord() { this->id = 0; }
    BaseRecord(int id) { this->id = id; }
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
    virtual BaseRecord Retrieve(SqlConnector conn, int id) = 0;
    
    
    /**
     * Updates the current record by its identifier
     * @param id - the identifier of record
     * @return result - the result of update operation
     */
    virtual bool UpdateRecord(SqlConnector conn) = 0;
    
    
    /**
     * Creates a new record
     * @return result - the result of create operation
     */
    virtual bool CreateRecord(SqlConnector conn) = 0;
};

#endif	/* BASERECORD_H */

