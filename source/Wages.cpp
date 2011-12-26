/* 
 * File:   Wages.cpp
 * Author: alex
 * 
 * Created on December 26, 2011, 2:20 AM
 */

#include "../header/Wages.h"

Wages::Wages(SqlConnector* const conn, User* u): connector(conn)
{
    DateTime* datestart = new DateTime();       // current DateTime -
    datestart->AddSomeDays(-31);                // minus 31 day
    DateTime* dateend = new DateTime();         // current DateTime
    this->Initialize();
    this->SetUser(u);
    this->DateStart(datestart);
    this->DateEnd(dateend);
    this->PostConstructor();
}

Wages::Wages(SqlConnector* const conn, User* u, DateTime* ds, DateTime* de): connector(conn)
{
    this->Initialize();
    this->SetUser(u);
    this->DateStart(ds);
    this->DateEnd(de);
    this->PostConstructor();
}

Wages::Wages(const Wages& orig)
{
    this->Initialize();
    this->SetWages(orig.GetWages());
    this->Premium(orig.Premium());
    this->SetUser(orig.GetUser());
    this->DateStart(orig.DateStart());
    this->DateEnd(orig.DateEnd());
}

Wages::~Wages()
{
    delete this->user;
    delete this->dateStart;
    delete this->dateEnd;
    this->Initialize();
}

void Wages::Initialize()
{    
    this->wages = 0;
    this->premium = 0;
    this->hours = 0;
    this->SetUser(NULL);
    this->DateStart(NULL);
    this->DateEnd(NULL);
}


void Wages::PostConstructor()
{
    vector<BaseRecord *> works;
    WorkTime* work;
    this->Hours(0);
    string where = "WHERE `user` = " + NumberToStringConverter<int>::Convert(this->GetUser()->GetId())
            + " AND `day` > " + NumberToStringConverter<int>::Convert(this->DateStart()->Timestamp())
            + " AND `day` < " + NumberToStringConverter<int>::Convert(this->DateEnd()->Timestamp());
    
    WorkTime* userWork = new WorkTime(this->connector);
    works = userWork->RetrieveTableRecords(where);
    for(int i = 0; i < works.size(); i++) {
        work = (WorkTime *) works[i];
        this->Hours(work->Hours());
    }


    // Calculate the wages
    this->SetWages(this->GetUser()->Wage() * hours);
}