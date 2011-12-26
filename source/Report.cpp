#include "../header/Report.h"

Report::Report(SqlConnector* const conn): BaseRecord(conn, "Report") { this->GetTemplate(); }
Report::Report(SqlConnector* const conn, int id): BaseRecord(conn, "Report", id) { this->Retrieve(); this->GetTemplate(); }

Report::Report(const Report& orig): BaseRecord(orig.connector, orig.table) 
{
    this->SetTask(orig.GetTask());
    this->SetProject(orig.GetProject());
    this->SetReport(orig.GetReport());
    this->Hours(orig.Hours());
    this->CreatedAt(orig.CreatedAt());
    this->Tmpl(orig.Tmpl());
}

Report::~Report()
{
    delete this->task;
    delete this->project;
    delete this->created_at;
}

void Report::InitializeRecord()
{
    this->task = NULL;
    this->project = NULL;
    this->created_at = NULL;
    this->hours = 0.0;
}

void Report::GetTemplate()
{
    MYSQL_RES* res;
    MYSQL_ROW row;
    
    res = this->connector->Query("SELECT `template` FROM `Templates` WHERE `module` = 'Report' LIMIT 0,1", SELECT);
    row = mysql_fetch_row(res);
    this->Tmpl(row[0]);
}

void Report::ProcessingReport()
{
    std::cout << "Its ProcessingReport" << std::endl;
}


string Report::GetSqlCreate() const
{
    string sql;
    
    sql = "INSERT INTO `" + this->table + "` (`task`, `project`, `report`, `hours`, `created_at`) VALUE ("
            + NumberToStringConverter<int>::Convert(this->GetTask()->GetId()) + ", "
            + NumberToStringConverter<int>::Convert(this->GetProject()->GetId()) + ", "
            + "'" + this->GetReport() + "', "
            + "'" + NumberToStringConverter<float>::Convert(this->Hours()) + "', "
            + NumberToStringConverter<int>::Convert(this->CreatedAt()->Timestamp()) + ")";
    return sql;
}


string Report::GetSqlUpdate() const
{
    string sql;
    
    sql = "UPDATE `" + this->table + "` SET "
            + "`task` = " + NumberToStringConverter<int>::Convert(this->GetTask()->GetId()) + ", "
            + "`project` = " + NumberToStringConverter<int>::Convert(this->GetProject()->GetId()) + ", "
            + "`report` = '" + this->GetReport() + "', "
            + "`hours` = '" + NumberToStringConverter<float>::Convert(this->Hours()) + "', "
            + "`created_at` = " + NumberToStringConverter<int>::Convert(this->CreatedAt()->Timestamp())
            + " WHERE `id` = " + NumberToStringConverter<int>::Convert(this->id);
    return sql;
}


bool Report::Retrieve()
{
    MYSQL_RES* res;
    MYSQL_ROW row;
    string sql;
    
    sql = "SELECT `id`, `task`, `project`, `report`, `hours`, `created_at` FROM `" 
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
    
    this->SetTask(new Task(this->connector, atoi(row[1])));
    this->SetProject(new Project(this->connector, atoi(row[2])));
    this->SetReport(row[3]);
    this->Hours(atof(row[4]));
    this->CreatedAt(new DateTime(atoi(row[5])));
    
    return true;
}


BaseRecord* Report::RetrieveRecord(int id)
{
    return new Report(this->connector, id);
}


vector<BaseRecord *> Report::RetrieveTableRecords(string where, string limit) const
{
    vector<BaseRecord *> reports;
    BaseRecord* baseRecord;
    MYSQL_RES* res;
    MYSQL_ROW row;
    Report* report;
    string sql;
    
    sql = "SELECT `id`, `task`, `project`, `report`, `hours`, `created_at` FROM `" 
            + this->table + "` " + where + " " + limit;
    
    try {
        res = this->connector->Query(sql, SELECT);
    }
    catch(MySQLRecordNotFound* rnf) {
        std::cout << rnf->what() << std::endl;
        exit(ERROR_MYSQL_QUERY);
    }
    
    while(row = mysql_fetch_row(res)) {
        report = new Report(this->connector);
        report->id = atoi(row[0]);
        report->SetTask(new Task(this->connector, atoi(row[1])));
        report->SetProject(new Project(this->connector, atoi(row[2])));
        report->SetReport(row[3]);
        report->Hours(atof(row[4]));
        report->CreatedAt(new DateTime(atoi(row[5])));
        baseRecord = report;
        reports.push_back(baseRecord);
    }
    
    return reports;
}


bool Report::IsSet() const
{
    MYSQL_RES* res;
    string sql;
    
    sql = "SELECT `id` FROM `" + this->table + "` WHERE "
            + "`task` = " + NumberToStringConverter<int>::Convert(this->GetTask()->GetId()) + " "
            + "AND `project` = " + NumberToStringConverter<int>::Convert(this->GetProject()->GetId()) + " "
            + "LIMIT 0, 2";
    res = this->connector->Query(sql, SELECT);
    
    if(mysql_num_rows(res) != 0) {
        return true;
    }
    else {
        return false;
    }
}