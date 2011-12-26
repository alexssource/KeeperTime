#include "../header/Project.h"

Project::Project(SqlConnector* const conn): BaseRecord(conn, "Project") { }
Project::Project(SqlConnector* const conn, int id): BaseRecord(conn, "Project", id) { this->Retrieve(); }

Project::Project(const Project& orig): BaseRecord(orig.connector, orig.table)
{
    this->Name(orig.Name());
    this->Description(orig.Description());
    this->SetTeam(orig.GetTeam());
    this->TimmingPlan(orig.TimmingPlan());
    this->SetStatus(orig.GetStatus());
    this->CreatedAt(orig.CreatedAt());
    this->ExpiredAt(orig.ExpiredAt());
    this->Deadline(orig.Deadline());
    this->Priority(orig.Priority());
}

Project::~Project()
{
    if(this->team != NULL) delete this->team;
    if(this->status != NULL) delete this->status;
    if(this->created_at != NULL) delete this->created_at;
    if(this->expired_at != NULL) delete this->expired_at;
    if(this->deadline != NULL) delete this->deadline;
    this->InitializeRecord();
}


void Project::InitializeRecord()
{
    this->team = NULL;
    this->status = NULL;
    this->created_at = NULL;
    this->expired_at = NULL;
    this->deadline = NULL;
}


string Project::GetSqlCreate() const
{
    string sql;
    
    sql = "INSERT INTO `" + this->table + "` (`name`, `description`, `team`, "
            + "`timming_plan`, `status`, `created_at`, `expired_at`, `deadline`, `priority`) "
            + "VALUE ('" + this->Name() + "', '" + this->Description() + "', "
            + NumberToStringConverter<int>::Convert(this->GetTeam()->GetId()) + ", '" 
            + NumberToStringConverter<float>::Convert(this->TimmingPlan()) + "', " 
            + NumberToStringConverter<int>::Convert(this->GetStatus()->GetId()) + ", "
            + NumberToStringConverter<int>::Convert(this->CreatedAt()->Timestamp()) + ", "
            + NumberToStringConverter<int>::Convert(this->ExpiredAt()->Timestamp()) + ", "
            + NumberToStringConverter<int>::Convert(this->Deadline()->Timestamp()) + ", "
            + NumberToStringConverter<int>::Convert(this->Priority()) + ")";
    return sql;
}


string Project::GetSqlUpdate() const
{
    string sql;
    
    sql = "UPDATE `" + this->table +"` SET "
            + "`name` = '" + this->Name() + "', "
            + "`description` = '" + this->Description() + "', "
            + "`team` = " + NumberToStringConverter<int>::Convert(this->GetTeam()->GetId()) + ", "
            + "`timming_plan` = '" + NumberToStringConverter<float>::Convert(this->TimmingPlan()) + "', "
            + "`status` = " + NumberToStringConverter<int>::Convert(this->GetStatus()->GetId()) + ", "
            + "`created_at` = " + NumberToStringConverter<int>::Convert(this->CreatedAt()->Timestamp()) + ", "
            + "`expired_at` = " + NumberToStringConverter<int>::Convert(this->ExpiredAt()->Timestamp()) + ", "
            + "`deadline` = " + NumberToStringConverter<int>::Convert(this->Deadline()->Timestamp()) + ", "
            + "`priority` = " + NumberToStringConverter<int>::Convert(this->Priority()) + " "
            + "WHERE `id` = " + NumberToStringConverter<int>::Convert(this->GetId());
    return sql;
}


bool Project::Retrieve()
{
    MYSQL_RES* res;
    MYSQL_ROW row;
    string sql;
    
    sql = "SELECT `id`, `name`, `description`, `team`, `timming_plan`, `status`, `created_at`, `expired_at`, `deadline`, `priority` "
            "FROM `" + this->table + "` "
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
    this->Description(row[2]);
    this->SetTeam(new Team(this->connector, atoi(row[3])));
    this->TimmingPlan(atof(row[4]));
    this->SetStatus(new Status(this->connector, atoi(row[5])));
    this->CreatedAt(new DateTime(atoi(row[6])));
    this->ExpiredAt(new DateTime(atoi(row[7])));
    this->Deadline(new DateTime(atoi(row[8])));
    this->Priority(atoi(row[9]));
    
    return true;
}


BaseRecord* Project::RetrieveRecord(int id)
{
    return new Project(this->connector, id);
}


vector<BaseRecord *> Project::RetrieveTableRecords(string where, string limit) const
{
    vector<BaseRecord *> projects;
    BaseRecord* baseRecord;
    MYSQL_RES* res;
    MYSQL_ROW row;
    Project* project;
    string sql;
    
    sql = "SELECT `id`, `name`, `description`, `team`, `timming_plan`, `status`, `created_at`, `expired_at`, `deadline`, `priority` FROM `" 
            + this->table + "` " + where + " " + limit;
    
    try {
        res = this->connector->Query(sql, SELECT);
    }
    catch(MySQLRecordNotFound* rnf) {
        std::cout << rnf->what() << std::endl;
        exit(ERROR_MYSQL_QUERY);
    }
    
    while(row = mysql_fetch_row(res)) {
        project = new Project(this->connector);
        project->id = atoi(row[0]);
        project->Name(row[1]);
        project->Description(row[2]);
        project->SetTeam(new Team(this->connector, atoi(row[3])));
        project->TimmingPlan(atof(row[4]));
        project->SetStatus(new Status(this->connector, atoi(row[5])));
        project->CreatedAt(new DateTime(atoi(row[6])));
        project->ExpiredAt(new DateTime(atoi(row[7])));
        project->Deadline(new DateTime(atoi(row[8])));
        project->Priority(atoi(row[9]));
        baseRecord = project;
        projects.push_back(baseRecord);
    }
    
    return projects;
}