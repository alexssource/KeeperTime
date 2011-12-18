/* 
 * File:   Team.cpp
 * Author: alex
 * 
 * Created on December 18, 2011, 7:32 PM
 */

#include "../header/Team.h"

Team::Team(SqlConnector* const conn): BaseRecord(conn, "Team") { }
Team::Team(SqlConnector* const conn, int id): BaseRecord(conn, "Team", id) { }

Team::Team(const Team& orig): BaseRecord(orig.connector, orig.table)
{
    this->Name(orig.Name());
    this->Manager(orig.Manager());
    this->CreatedAt(orig.CreatedAt());
}

Team::~Team()
{
    if(this->manager != NULL) {
        delete this->manager;
        this->manager = NULL;
    }
}


Team::InitializeRecord()
{
    this->manager = NULL;
}


string Team::GetSqlCreate() const
{
    string sql;
    
    sql = "INSERT INTO `" + this->table + "` (`name`, `manager`, `created_at`) "
            + "VALUE ('" + this->name + "', " 
            + NumberToStringConverter<int>::Convert(this->Manager()->GetId()) + ", "
            + this->CreatedAt().ToString() + ")";
    
    return sql;
}

string Team::GetSqlUpdate() const
{
    string sql;
    
    sql = "UPDATE `" + this->table + "` SET `name`='" + this->name + "', "
            + "`manager` = " + NumberToStringConverter<int>::Convert(this->Manager()->GetId()) + ", "
            + "`created_at` = " + this->CreatedAt().ToString() + " "
            + "WHERE `id` = " + NumberToStringConverter<int>::Convert(this->id);

    return sql;
}


bool Team::Retrieve()
{
    MYSQL_RES* res;
    MYSQL_ROW row;
    string sql;
    
    sql = "SELECT `id`, `name`, `manager`, `created_at` FROM `" + this->table 
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
    this->Manager(atoi(row[2]));
    this->CreatedAt(row[3]);
    return true;
}


BaseRecord* Team::RetrieveRecord(int id)
{
    Team* tm = new Team(this->connector, id);
    tm->Retrieve();
    return tm;
}


vector <BaseRecord *> Team::RetrieveTableRecords(string where, string limit) const
{
    vector<BaseRecord *> teams;
    BaseRecord* baseRecord;
    MYSQL_RES* res;
    MYSQL_ROW row;
    Team* team;
    string sql;
    
    sql = "SELECT `id`, `name`, `manager`, `created_at` FROM `" + this->table + "` "
            + where + " " + limit;
    
    try {
        res = this->connector->Query(sql, SELECT);
    }
    catch(MySQLRecordNotFound* rnf) {
        std::cout << rnf->what() << std::endl;
        exit(ERROR_MYSQL_QUERY);
    }
    
    while(row = mysql_fetch_row(res)) {
        team = new Team(this->connector);
        team->id = atoi(row[0]);
        team->Name(row[1]);
        team->Manager(atoi(row[2]));
        team->CreatedAt(row[3]);
        baseRecord = team;
        teams.push_back(baseRecord);
    }
    
    return teams;
}