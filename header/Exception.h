/* 
 * File:   Exception.h
 * Author: Alex Kozlov <alexssource@gmail.com>
 *
 * Created on December 10, 2011, 6:15 PM
 */

#ifndef EXCEPTION_H
#define	EXCEPTION_H

#include <string>
#include <exception>
#include "ERROR_CODES.h"

using namespace std;

class Exception: public exception
{
private:
    int code;
    string type;
    string message;
    
    void Initialize(int c, string msg, string t = "")
    {
        this->code = c;
        this->message = msg;
        this->type = t;
    }
    
public:
    /**
     * This object contained the information about your exception,
     * such as exception's code, type, message
     * @param <int> c - the code of exception (need get from ERROR_CODES.h)
     * @param <string> msg - the message of exception
     */
    Exception(int c, string msg);
    
    
    /**
     * This object contained the information about your exception,
     * such as exception's code, type, message
     * @param <int> c - the code of exception (need get from ERROR_CODES.h)
     * @param <string> t - the type of exception (example, "MYSQL_ERROR")
     * @param <string> msg - the message of exception
     */
    Exception(int c, string t, string msg);
    
    
    /**
     * Remove the instance of current exception
     */
    virtual ~Exception() throw() { };
    
    
    /**
     * Gets the full information about your exception (example, "_21. MYSQL_ERROR: Unable to connect")
     * @return char* information
     */
    virtual const char* what() const throw();
    
    
    
    // Properties (readonly)
    
    /**
     * Gets the exception code
     * @return int code
     */
    int Code() const { return this->code; }
    
    /**
     * Gets the exception type
     * @return string type
     */
    string Type() const { return this->type; }
    
    
    /**
     * Gets the exception message
     * @return string message
     */
    string Message() const { return this->message; }
};


class MySQLRecordNotFound: public Exception
{
public:
    MySQLRecordNotFound(): Exception(ERROR_MYSQL_QUERY, ERROR_TYPE_MYSQL, "No Records Found") { }
    virtual ~MySQLRecordNotFound() throw() { };
};


class MySQLNoUpdateRecord: public Exception
{
public:
    MySQLNoUpdateRecord(string mysql_error = ""): Exception(ERROR_MYSQL_QUERY, ERROR_TYPE_MYSQL, "No Updated Records Found: " + mysql_error) { }
    virtual ~MySQLNoUpdateRecord() throw() { };
};

class MySQLNoInsertRecord: public Exception
{
public:
    MySQLNoInsertRecord(string mysql_error = ""): Exception(ERROR_MYSQL_QUERY, ERROR_TYPE_MYSQL, "Can\'t insert the records: " + mysql_error) { }
    virtual ~MySQLNoInsertRecord() throw() { }
};

class MySQLNoDeleteRecord: public Exception
{
public:
    MySQLNoDeleteRecord(string mysql_error = ""): Exception(ERROR_MYSQL_QUERY, ERROR_TYPE_MYSQL, "Can\'t delete the record: " + mysql_error) { }
    virtual ~MySQLNoDeleteRecord() throw() { }
};

class MySQLQueryException: public Exception
{
public:
    MySQLQueryException(string sql, string mysql_say = ""): Exception(ERROR_MYSQL_QUERY, ERROR_TYPE_MYSQL, 
        "Error Send Query: " + sql + "\nMysql Say: " + mysql_say) { };
        virtual ~MySQLQueryException() throw() { }
};

class MySQLRecordNotUnique: public Exception
{
public:
    MySQLRecordNotUnique(): Exception(ERROR_MYSQL_QUERY, ERROR_TYPE_MYSQL, 
        "Can't Create a record: MySQL Record Is Set (Not Unique)") { };
        virtual ~MySQLRecordNotUnique() throw() { }
};

#endif	/* EXCEPTION_H */