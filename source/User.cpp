#include "../header/User.h"

User::User(SqlConnector* const conn): BaseRecord(conn, "User") { }
User::User(SqlConnector* const conn, int id): BaseRecord(conn, "User", id) { this->Retrieve(); }

User::User(const User& orig): BaseRecord(orig.connector, orig.table)
{
    this->Name(orig.Name());
    this->Surname(orig.Surname());
    this->Login(orig.Login());
    this->Password(orig.Password());
    this->Email(orig.Email());
    this->Wage(orig.Wage());
    this->SetGroup(orig.GetGroup());
    this->SetTeam(orig.GetTeam());
    this->CreatedAt(orig.CreatedAt());
}

User::~User()
{
    if(this->team != NULL) {
        delete this->team;
        this->team = NULL;
    }
    
    if(this->group != NULL) {
        delete this->group;
        this->group = NULL;
    }
}


void User::InitializeRecord()
{
    this->group = NULL;
    this->team = NULL;
}


string User::GetSqlCreate() const
{
    string sql;
    
    sql = "INSERT INTO `" + this->table + "` (`name`, `surname`, `login`, "
            + "`password`, `email`, `group`, `team`, `created_at`, `wage`) "
            + "VALUE ('" + this->Name() + "', '" + this->Surname() + "', '" + this->Login() + "', "
            + "'" + this->Password() + "', '" + this->Email() + "', " 
            + NumberToStringConverter<int>::Convert(this->GetGroup()->GetId()) + ", "
            + NumberToStringConverter<int>::Convert(this->GetTeam()->GetId()) + ", '" 
            + NumberToStringConverter<int>::Convert(this->CreatedAt()->Timestamp()) + "', '"
            + NumberToStringConverter<float>::Convert(this->Wage()) + "')";
    return sql;
}


string User::GetSqlUpdate() const
{
    string sql;
    
    sql = "UPDATE `" + this->table + "` SET `name`='" + this->Name() + "', "
            + "`surname` = '" + this->Surname() + "', "
            + "`login` = '" + this->Login() + "', "
            + "`password` = '" + this->Password() + "', "
            + "`email` = '" + this->Email() + "', "
            + "`group` = " + NumberToStringConverter<int>::Convert(this->GetGroup()->GetId()) + ", "
            + "`team` = " + NumberToStringConverter<int>::Convert(this->GetTeam()->GetId()) + ", "
            + "`created_at` = '" + NumberToStringConverter<int>::Convert(this->CreatedAt()->Timestamp()) + "', "
            + "`wage` = '" + NumberToStringConverter<float>::Convert(this->Wage()) + "' "
            + "WHERE `id` = " + NumberToStringConverter<int>::Convert(this->id);
    return sql;
}


bool User::Retrieve()
{
    MYSQL_RES* res;
    MYSQL_ROW row;
    string sql;
    
    sql = "SELECT `id`, `name`, `surname`, `login`, `password`, `email`, `group`, `team`, `created_at`, `wage` FROM `" 
            + this->table + "` "
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
    this->Surname(row[2]);
    this->Login(row[3]);
    this->Password(row[4]);
    this->Email(row[5]);
    this->group = new Group(this->connector, atoi(row[6]));
    this->team = new Team(this->connector, atoi(row[7]));
    this->created_at = new DateTime(atoi(row[8]));
    this->Wage(atof(row[9]));

    return true;
}


BaseRecord* User::RetrieveRecord(int id)
{
    User* usr = new User(this->connector, id);
    return usr;
}


vector<BaseRecord *> User::RetrieveTableRecords(string where, string limit) const
{
    vector<BaseRecord *> users;
    BaseRecord* baseRecord;
    MYSQL_RES* res;
    MYSQL_ROW row;
    User* user;
    string sql;
    
    sql = "SELECT `id`, `name`, `surname`, `login`, `password`, `email`, `group`, `team`, `created_at`, `wage` FROM `" 
            + this->table + "` "
            + where + " " + limit;
    
    try {
        res = this->connector->Query(sql, SELECT);
    }
    catch(MySQLRecordNotFound* rnf) {
        std::cout << rnf->what() << std::endl;
        exit(ERROR_MYSQL_QUERY);
    }
    
    while(row = mysql_fetch_row(res)) {
        user = new User(this->connector);
        user->id = atoi(row[0]);
        user->Name(row[1]);
        user->Surname(row[2]);
        user->Login(row[3]);
        user->Password(row[4]);
        user->Email(row[5]);
        user->SetGroup(atoi(row[6]));
        user->SetTeam(atoi(row[7]));
        user->CreatedAt(atoi(row[8]));
        user->Wage(atof(row[9]));
        
        baseRecord = user;
        users.push_back(baseRecord);
    }
    
    return users;
}


bool User::IsSet() const
{
    MYSQL_RES* res;
    string sql;
    
    sql = "SELECT `id` FROM `" + this->table + "` WHERE `login` = '" + this->Login() + "' LIMIT 0, 2";
    res = this->connector->Query(sql, SELECT);
    
    if(mysql_num_rows(res) != 0) {
        return true;
    }
    else {
        return false;
    }
}

bool User::RetrieveByLoginPass()
{
    MYSQL_RES* res;
    MYSQL_ROW row;
    string sql;
    
    sql = "SELECT `id`, `name`, `surname`, `login`, `password`, `email`, `group`, `team`, `created_at`, `wage` FROM `" 
            + this->table + "` "
            + "WHERE `login` = '" + this->Login() + "' "
            + "AND `password` = '" + this->Password() + "' "
            + "LIMIT 0, 1";
    
    res = this->connector->Query(sql, SELECT);
    if(mysql_num_rows(res) == 0) {
        throw new MySQLAuthorizationException(this->Login(), this->Password());
    }
    row = mysql_fetch_row(res);
    
    this->id = atoi(row[0]);
    this->Name(row[1]);
    this->Surname(row[2]);
    this->Password(row[4]);
    this->Email(row[5]);
    this->SetGroup(atoi(row[6]));
    this->SetTeam(atoi(row[7]));
    this->CreatedAt(atoi(row[8]));
    this->Wage(atof(row[9]));
    
    return true;
}