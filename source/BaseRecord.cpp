#include "../header/BaseRecord.h"

vector<MYSQL_ROW> BaseRecord::RetrieveTableRows(string where = "", string limit = "")
{
    MYSQL_RES* res;
    MYSQL_ROW sqlrow;
    string sql = "SELECT * FROM `" + this->table + "` " + where + " " + limit;
    vector<MYSQL_ROW> records = new vector<MYSQL_ROW>();
    
    res = this->connector->Query(sql, SELECT);
    while(sqlrow = mysql_fetch_row(res)) {
        records.push_back(sqlrow);
    }
    
    return records;
}