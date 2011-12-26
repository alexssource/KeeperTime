#include "../header/Task.h"

Task::Task(SqlConnector* const conn): BaseRecord(conn, "Task") { }
Task::Task(SqlConnector* const conn, int id): BaseRecord(conn, "Task", id) { this->Retrieve(); }

Task::Task(const Task& orig): BaseRecord(orig.connector, orig.table) 
{
    this->Name(orig.Name());
    this->Title(orig.Title());
    this->Description(orig.Description());
    this->TimmingPlan(orig.TimmingPlan());
    this->SetProject(orig.GetProject());
    this->SetUser(orig.GetUser());
    this->SetStatus(orig.GetStatus());
    this->CreatedAt(orig.CreatedAt());
    this->Priority(orig.Priority());
}

Task::~Task()
{
    delete this->project;
    delete this->user;
    delete this->status;
    delete this->created_at;
}


void Task::InitializeRecord()
{
    this->project = NULL;
    this->user = NULL;
    this->status = NULL;
    this->created_at = NULL;
    this->InitializeRecord();
}


string Task::GetSqlCreate() const
{
    string sql;
    
    sql = "INSERT INTO `" + this->table + "` (`name`, `title`, `description`, `timming_plan`, "
            + "`project`, `user`, `status`, `created_at`, `priority`) VALUE ("
            + "'" + this->Name() + "', "
            + "'" + this->Title() + "', "
            + "'" + this->Description() + "', "
            + "'" + NumberToStringConverter<float>::Convert(this->TimmingPlan()) + "', " 
            + NumberToStringConverter<int>::Convert(this->GetProject()->GetId()) + ", "
            + NumberToStringConverter<int>::Convert(this->GetUser()->GetId()) + ", "
            + NumberToStringConverter<int>::Convert(this->GetStatus()->GetId()) + ", "
            + NumberToStringConverter<int>::Convert(this->CreatedAt()->Timestamp()) + ", "
            + NumberToStringConverter<int>::Convert(this->Priority()) + ")";
    return sql;
}


string Task::GetSqlUpdate() const
{
    string sql;
    
    sql = "UPDATE `" + this->table +"` SET "
            + "`name` = '" + this->Name() + "', "
            + "`title` = '" + this->Title() + "', "
            + "`description` = '" + this->Description() + "', "
            + "`timming_plan` = '" + NumberToStringConverter<float>::Convert(this->TimmingPlan()) + "', "
            + "`project` = " + NumberToStringConverter<int>::Convert(this->GetProject()->GetId()) + ", "
            + "`user` = " + NumberToStringConverter<int>::Convert(this->GetUser()->GetId()) + ", "
            + "`status` = " + NumberToStringConverter<int>::Convert(this->GetStatus()->GetId()) + ", "
            + "`created_at` = " + NumberToStringConverter<int>::Convert(this->CreatedAt()->Timestamp()) + ", "
            + "`priority` = " + NumberToStringConverter<int>::Convert(this->Priority()) + " "
            + "WHERE `id` = " + NumberToStringConverter<int>::Convert(this->GetId());
    return sql;
}


bool Task::Retrieve()
{
    MYSQL_RES* res;
    MYSQL_ROW row;
    string sql;
    
    sql = "SELECT `id`, `name`, `title`, `description`, `timming_plan`, `project`, `user`, `status`, `created_at`, `priority` FROM `" 
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
    
    this->Name(row[1]);
    this->Title(row[2]);
    this->Description(row[3]);
    this->TimmingPlan(atof(row[4]));
    this->SetProject(new Project(this->connector, atoi(row[5])));
    this->SetUser(new User(this->connector, atoi(row[6])));
    this->SetStatus(new Status(this->connector, atoi(row[7])));
    this->CreatedAt(new DateTime(atoi(row[8])));
    this->Priority(atoi(row[9]));
    
    return true;
}


BaseRecord* Task::RetrieveRecord(int id)
{
    return new Task(this->connector, id);
}


vector<BaseRecord *> Task::RetrieveTableRecords(string where, string limit) const
{
    vector<BaseRecord *> tasks;
    BaseRecord* baseRecord;
    MYSQL_RES* res;
    MYSQL_ROW row;
    Task* task;
    string sql;
    
    sql = "SELECT `id`, `name`, `title`, `description`, `timming_plan`, `project`, `user`, `status`, `created_at`, `priority` "
            + this->table + "` " + where + " " + limit;
    
    try {
        res = this->connector->Query(sql, SELECT);
    }
    catch(MySQLRecordNotFound* rnf) {
        std::cout << rnf->what() << std::endl;
        exit(ERROR_MYSQL_QUERY);
    }
    
    while(row = mysql_fetch_row(res)) {
        task = new Task(this->connector);
        task->id = atoi(row[0]);
        task->Name(row[1]);
        task->Title(row[2]);
        task->Description(row[3]);
        task->TimmingPlan(atof(row[4]));
        task->SetProject(new Project(this->connector, atoi(row[5])));
        task->SetUser(new User(this->connector, atoi(row[6])));
        task->SetStatus(new Status(this->connector, atoi(row[7])));
        task->CreatedAt(new DateTime(atoi(row[8])));
        task->Priority(atoi(row[9]));
        baseRecord = task;
        tasks.push_back(baseRecord);
    }
    
    return tasks;
}