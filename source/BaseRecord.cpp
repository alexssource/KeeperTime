#include "../header/BaseRecord.h"

vector<string *> BaseRecord::RetrieveTableRows(string where, string limit) const
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


bool BaseRecord::CreateRecord() const
{
    string sql = this->GetSqlCreate();
    
    try {
        this->connector->Query(sql, INSERT);
    }
    catch(MySQLNoInsertRecord* nir) {
        std::cout << "Error when trying to update record:" << std::endl;
        std::cout << "\t" << nir->what() << std::endl;
        return false;
    }
    
    return true;
}


bool BaseRecord::UpdateRecord() const
{
    string sql = this->GetSqlUpdate();
    
    try {
        this->connector->Query(sql, UPDATE);
    }
    catch(MySQLNoUpdateRecord* nur) {
        std::cout << "Error when trying to update record:" << std::endl;
        std::cout << "\t" << nur->what() << std::endl;
        return false;
    }
    
    return true;
}


bool BaseRecord::DeleteRecord() const
{
    string sql = this->GetSqlDelete();
    
    try {
        this->connector->Query(sql, DELETE);
    }
    catch(MySQLNoDeleteRecord* ndr) {
        std::cout << ndr->Message() << std::endl;
        return false;
    }

    return true;
}


string BaseRecord::GetSqlDelete() const
{
    string sql;
    
    sql = "DELETE FROM `" + this->table + "` WHERE `id` = " 
            + NumberToStringConverter<int>::Convert(this->id);
    
    return sql;
}