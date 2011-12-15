/* 
 * File:   SqlConnector.cpp
 * Author: alex
 * 
 * Created on December 5, 2011, 12:15 PM
 */

#include "../header/SqlConnector.h"

SqlConnector::SqlConnector(string host, string user, string pass, string database)
{
    this->Initialize(host, user, pass, database);
    if(!this->Connect()) {
        string error = "MySQL ERROR: ";
        error.append(mysql_error(&this->connection));
        throw new Exception(ERROR_MYSQL_CONNECT, ERROR_TYPE_MYSQL, error);
    }
}

SqlConnector::~SqlConnector()
{
    mysql_close(&this->connection);
}

void SqlConnector::Initialize(string host, string user, string pass, string database)
{
    this->host = host;
    this->user = user;
    this->pass = pass;
    this->database = database;
}

bool SqlConnector::Connect()
{
    mysql_init(&this->connection);

    return mysql_real_connect(&this->connection, this->host.c_str(), this->user.c_str(), 
            this->pass.c_str(), this->database.c_str(), 0, NULL, 0);
}


MYSQL_RES* SqlConnector::Query(string sql, MYSQL_QUERY_TYPE type)
{
    int result;
    MYSQL_RES* res = NULL; 
    
    result = mysql_query(&this->connection, sql.c_str());
    if(result != 0) throw new MySQLQueryException(sql);
    
    res = mysql_use_result(&this->connection);
    
    if(!res && type == SELECT) {
        throw new MySQLRecordNotFound();
    }
    
    return res;
}