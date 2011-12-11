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
#include "mysql/mysql.h"
#include "ERROR_CODES.h"

using namespace std;

class SqlConnector
{
private:
    MYSQL connection;
    string user;
    string pass;
    string host;
    string database;
    string table;
    string query;
    
protected:
    bool Connect();
    void Initialize(string host, string user, string pass, string database);
    
public:
    SqlConnector(string host, string user, string pass, string database);
    virtual ~SqlConnector();
    
    
    // Properties
    string GetTable() const { return this->table; }
    void SetTable(string t) { this->table = t; }
    string GetQuery() const { return this->query; }
    void SetQuery(string sql) { this->query = sql; }
};

#endif	/* SQLCONNECTOR_H */

