#include "../header/Status.h"

Status::Status(SqlConnector* const conn): BaseRecord(conn, "Status") { }
Status::Status(SqlConnector* const conn, int id): BaseRecord(conn, "Status", id) { this->Retrieve(); }
Status::~Status() { }

Status::Status(const Status& orig): BaseRecord(orig.connector, orig.table) {
    if(orig.GetId()) {
        this->id = orig.GetId();
    }
    this->Name(orig.Name());
}


string Status::GetSqlCreate() const
{
    string sql;
    
    sql = "INSERT INTO `" + this->table + "` (`name`) VALUE ('" + this->Name() + "')";
    return sql;
}

string Status::GetSqlUpdate() const
{
    string sql;
    
    sql = "UPDATE `" + this->table +"` SET `name` = '" + this->Name() + "' WHERE `id` = " 
            + NumberToStringConverter<int>::Convert(this->GetId());
    return sql;
}

bool Status::Retrieve()
{
    MYSQL_RES* res;
    MYSQL_ROW row;
    string sql;
    
    sql = "SELECT `id`, `name` FROM `" + this->table + "` "
            + "WHERE `id` = " + NumberToStringConverter<int>::Convert(this->id)
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
    return true;
}


BaseRecord* Status::RetrieveRecord(int id)
{
    Status* status = new Status(this->connector, id);
    return status;
}


vector<BaseRecord *> Status::RetrieveTableRecords(string where, string limit) const
{
    vector<BaseRecord *> statuses;
    BaseRecord* baseRecord;
    MYSQL_RES* res;
    MYSQL_ROW row;
    Status* status;
    string sql;
    
    sql = "SELECT `id`, `name` FROM `" + this->table + "` " + where + " " + limit;
    
    try {
        res = this->connector->Query(sql, SELECT);
    }
    catch(MySQLRecordNotFound* rnf) {
        std::cout << rnf->what() << std::endl;
        exit(ERROR_MYSQL_QUERY);
    }
    
    while(row = mysql_fetch_row(res)) {
        status = new Status(this->connector);
        status->id = atoi(row[0]);
        status->Name(row[1]);
        baseRecord = status;
        statuses.push_back(baseRecord);
    }
    
    return statuses;
}


bool Status::IsSet() const
{
    MYSQL_RES* res;
    string sql;
    
    sql = "SELECT `id` FROM `" + this->table + "` WHERE `name` = '" + this->Name() + "' LIMIT 0, 2";
    res = this->connector->Query(sql, SELECT);
    
    if(mysql_num_rows(res) != 0) {
        return true;
    }
    else {
        return false;
    }
}