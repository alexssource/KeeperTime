/* 
 * File:   Group.cpp
 * Author: alex
 * 
 * Created on December 17, 2011, 3:34 PM
 */

#include "../header/Group.h"

Group::Group(SqlConnector* const conn): BaseRecord(conn, "Group") { }
Group::Group(SqlConnector* conn, int id): BaseRecord(conn, "Group", id) { this->Retrieve(); }

Group::Group(const Group& orig): BaseRecord(orig.connector, orig.table)
{
    this->id = orig.id;
    this->is_admin = orig.is_admin;
    this->is_manager = orig.is_manager;
    this->name = orig.name;
}

Group::~Group() { }


string Group::GetSqlCreate() const
{
    string sql;
    
    sql = "INSERT INTO `" + this->table + "` (`name`, `is_admin`, `is_manager`) "
            + "VALUE ('" + this->name + "', " + ((this->is_admin) ? "1" : "0") + ", "
            + ((this->is_manager) ? "1" : "0") + ")";

    return sql;
}

string Group::GetSqlUpdate() const
{
    string sql;
    
    sql = "UPDATE `" + this->table + "` SET `name`='" + this->name + "', "
            + "`is_admin` = " + ((this->is_admin) ? "1" : "0") + ", "
            + "`is_manager` = " + ((this->is_manager) ? "1" : "0") + " "
            + "WHERE `id` = " + NumberToStringConverter<int>::Convert(this->id);
    
    return sql;
}

string Group::GetSqlDelete() const
{
    string sql;
    
    sql = "DELETE FROM `" + this->table + "` WHERE `id` = " 
            + NumberToStringConverter<int>::Convert(this->id);
    
    return sql;
}


void Group::InitializeRecord()
{
    this->is_admin = false;
    this->is_manager= false;
}

bool Group::Retrieve()
{
    MYSQL_RES* res;
    MYSQL_ROW row;
    string sql;
    
    sql = "SELECT `id`, `name`, `is_admin`, `is_manager` FROM `" + this->table 
            + "` WHERE `id` = " + NumberToStringConverter<int>::Convert(this->id)
            + " LIMIT 0, 1";
    
    try {
        res = this->connector->Query(sql, SELECT);
    }
    catch(MySQLRecordNotFound* rnf) {
        std::cout << rnf->what() << std::endl;
        return false;
    }
    
    row = mysql_fetch_row(res);
    
    this->Name(row[1]);
    this->IsAdmin(row[2]);
    this->IsManager(row[3]);
    return true;
}


BaseRecord* Group::RetrieveRecord(int pid)
{
    Group* gr = new Group(this->connector, pid);
    gr->Retrieve();
    return gr;
}


vector<BaseRecord *> Group::RetrieveTableRecords(string where, string limit) const
{
    vector<BaseRecord *> groups;
    BaseRecord* baseRecord;
    MYSQL_RES* res;
    MYSQL_ROW row;
    Group* group;
    string sql;
    
    sql = "SELECT `id`, `name`, `is_admin`, `is_manager` FROM `" + this->table + "` "
            + where + " " + limit;
    
    try {
        res = this->connector->Query(sql, SELECT);
    }
    catch(MySQLRecordNotFound* rnf) {
        std::cout << rnf->what() << std::endl;
        exit(ERROR_MYSQL_QUERY);
    }
    
    while(row = mysql_fetch_row(res)) {
        group = new Group(this->connector);
        group->id = atoi(row[0]);
        group->Name(row[1]);
        group->IsAdmin(atoi(row[2]));
        group->IsManager(atoi(row[3]));
        baseRecord = group;
        groups.push_back(baseRecord);
    }
    
    return groups;
}