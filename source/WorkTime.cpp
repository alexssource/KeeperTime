#include "../header/WorkTime.h"

WorkTime::WorkTime(SqlConnector* const conn): BaseRecord(conn, "WorkTime") { }
WorkTime::WorkTime(SqlConnector* const conn, int id): BaseRecord(conn, "WorkTime", id) { this->Retrieve(); }

WorkTime::WorkTime(const WorkTime& orig): BaseRecord(orig.connector, orig.table)
{
    this->Day(orig.Day());
    this->Hours(orig.Hours());
    this->SetUser(orig.GetUser());
}

WorkTime::~WorkTime()
{
    delete this->day;
    delete this->user;
    this->InitializeRecord();
}


void WorkTime::InitializeRecord()
{
    this->day = NULL;
    this->user = NULL;
    this->hours = 0.0;
}

void WorkTime::AddTodayTime(float delta)
{
    this->hours += delta;
}


string WorkTime::GetSqlCreate() const
{
    string sql;
    
    sql = "INSERT INTO `" + this->table + "` (`day`, `hours`, `user`) VALUE ("
            + NumberToStringConverter<int>::Convert(this->Day()->Timestamp()) + ", "
            + "'" + NumberToStringConverter<float>::Convert(this->Hours()) + "', "
            + NumberToStringConverter<int>::Convert(this->GetUser()->GetId()) + ")";
    return sql;
}


string WorkTime::GetSqlUpdate() const
{
    string sql;
    
    sql = "UPDATE `" + this->table + "` SET "
            + "`day` = " + NumberToStringConverter<int>::Convert(this->Day()->Timestamp()) + ", "
            + "`hours` = '" + NumberToStringConverter<float>::Convert(this->Hours()) + "', "
            + "`user` = " + NumberToStringConverter<int>::Convert(this->GetUser()->GetId()) + " "
            + "WHERE `id` + " + NumberToStringConverter<int>::Convert(this->id);
    return sql;
}


bool WorkTime::Retrieve()
{
    MYSQL_RES* res;
    MYSQL_ROW row;
    string sql;
    
    sql = "SELECT `id`, `day`, `hours`, `user` FROM `" 
            + this->table + "` "
            + "WHERE `id` = " + NumberToStringConverter<int>::Convert(this->id) + " LIMIT 0, 1";
    
    try {
        res = this->connector->Query(sql, SELECT);
    }
    catch(MySQLRecordNotFound* rnf) {
        std::cout << rnf->what() << std::endl;
        return false;
    }
    
    row = mysql_fetch_row(res);
    
    this->Day(new DateTime(atoi(row[1])));
    this->Hours(atof(row[2]));
    this->SetUser(new User(this->connector, atoi(row[3])));
    
    return true;
}


BaseRecord* WorkTime::RetrieveRecord(int id)
{
    return new WorkTime(this->connector, id);
}


vector<BaseRecord *> WorkTime::RetrieveTableRecords(string where, string limit) const
{
    vector<BaseRecord *> works;
    BaseRecord* baseRecord;
    MYSQL_RES* res;
    MYSQL_ROW row;
    WorkTime* work;
    string sql;
    
    sql = "SELECT `id`, `day`, `hours`, `user` FROM `" 
            + this->table + "` " + where + " " + limit;
    
    try {
        res = this->connector->Query(sql, SELECT);
    }
    catch(MySQLRecordNotFound* rnf) {
        std::cout << rnf->what() << std::endl;
        exit(ERROR_MYSQL_QUERY);
    }
    
    while(row = mysql_fetch_row(res)) {
        work = new WorkTime(this->connector);
        work->id = atoi(row[0]);
        work->Day(new DateTime(atoi(row[1])));
        work->Hours(atof(row[2]));
        work->SetUser(new User(this->connector, atoi(row[3])));
        baseRecord = work;
        works.push_back(baseRecord);
    }
    
    return works;
}


bool WorkTime::IsSet() const
{
    MYSQL_RES* res;
    string sql;
    DateTime* dayStart = new DateTime();
    DateTime* dayEnd = new DateTime();
    
    dayStart->Hour(0);
    dayStart->Minute(0);
    dayStart->Minute(0);
    dayStart->DateToTimestamp();
    
    dayEnd->Hour(23);
    dayEnd->Minute(59);
    dayEnd->Seconds(59);
    dayEnd->DateToTimestamp();
    
    sql = "SELECT `id` FROM `" + this->table + "` WHERE "
            + "`user` = " + NumberToStringConverter<int>::Convert(this->GetUser()->GetId()) + " "
            + "AND `day` > " + NumberToStringConverter<int>::Convert(dayStart->Timestamp()) + " "
            + "AND `day` < " + NumberToStringConverter<int>::Convert(dayEnd->Timestamp()) + " "
            + "LIMIT 0, 2";
    res = this->connector->Query(sql, SELECT);
    
    if(mysql_num_rows(res) != 0) {
        return true;
    }
    else {
        return false;
    }
}