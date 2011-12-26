/* 
 * File:   SqlConnector.h
 * Author: alex
 *
 * Created on December 5, 2011, 12:15 PM
 */

#ifndef SQLCONNECTOR_H
#define	SQLCONNECTOR_H

#include <iostream>
#include <string>
#include <cstdlib>
#include "mysql/mysql.h"
#include "ERROR_CODES.h"
#include "Exception.h"

using namespace std;

class SqlConnector
{
private:
    MYSQL connection;
    string user;
    string pass;
    string host;
    string database;
    
protected:
    bool Connect();
    void Initialize(string host, string user, string pass, string database);
    void SetCharset();
    
public:
    SqlConnector(string host, string user, string pass, string database);
    virtual ~SqlConnector();
    MYSQL_RES* Query(string sql, MYSQL_QUERY_TYPE type);
    MYSQL GetConnection() const { return this->connection; }
    int GetLastInsertedId();
};

#endif	/* SQLCONNECTOR_H */

