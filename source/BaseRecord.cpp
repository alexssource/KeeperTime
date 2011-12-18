#include "../header/BaseRecord.h"

vector<string *> BaseRecord::RetrieveTableRows(string where, string limit)
{
    MYSQL_RES* res;
    MYSQL_ROW sqlrow;
    string sql = "SELECT * FROM `" + this->table + "` " + where + " " + limit;
    vector<string *> records;

    try {
        res = this->connector->Query(sql, SELECT);
    }
    catch(Exception e) {
        std::cout << "Exception: " << e.what() << endl;
    }
    while(sqlrow = mysql_fetch_row(res)) {
        string* srow = new string[sizeof(sqlrow)];
        for(int i = 0; i < sizeof(sqlrow); i++) {
            srow[i] = (string)sqlrow[i];
        }
        records.push_back(srow);
    }
    return records;
}