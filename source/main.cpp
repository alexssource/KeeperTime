/*
 * File:   main.cpp
 * Author: alex
 *
 * Created on November 17, 2011, 12:15 PM
 */

/**
 * Console Presentation
 */

#include <iostream>
#include <string>
#include <vector>
#include "../header/ERROR_CODES.h"
#include "../header/SqlConnector.h"
#include "../header/Group.h"
#include "../header/BaseRecord.h"
#include "../header/DateTime.h"
#include "header/User.h"
#include "header/Status.h"
#include "header/Project.h"
#include "header/Task.h"
#include "header/WorkTime.h"
#include "header/Report.h"
#include "header/Wages.h"

using namespace std;

int main()
{
    vector<BaseRecord *> groups;
    SqlConnector* SqlConn;
    
    try {
        SqlConn = new SqlConnector("localhost", "keepertime", "KeeperTime", "KeeperTime");
    }
    catch(Exception* e) {
        cout << e->what() << endl;
        delete SqlConn;
        return e->Code();
    }

    ////// Logic For MyProgram //////
    
    ////// End Logic MyProgram //////
    cout << "Hi, its console!" << endl;
    
    delete SqlConn;
    return 0;
}


/**
 * Qt presentation
 * 
#include <QtGui/QApplication>

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);

    // create and show your widgets here

    return app.exec();
}
*/





/** Testing Classes
 
    group = new Group(SqlConn);
    groups = group->RetrieveTableRows();
    

    for(int i = 0; i < groups.size(); i++) {
        cout << groups[i][0] << ": " << groups[i][1] << " " 
                << groups[i][2] << " " << groups[i][3] << endl;
    }    
    delete group;
 
 */

/**
     Group* group = new Group(SqlConn);
    groups = group->RetrieveTableRecords();
    for(int i = 0; i < groups.size(); i++) {
        cout << "Group: " << ((Group*)groups[i])->Name() << endl;
    }
 */


    /*
    // Create a new Team
    dev->Name("DevTeam");
    dev->CreatedAt(nowDate);
    dev->Save();
    */


// User Registration
    /*
    User* Alex = new User(SqlConn);    
    Alex->Name("Sasha");
    Alex->Surname("Kozlov");
    Alex->Login("gaizjad");
    Alex->Password("3");
    Alex->Email("gaizjad@mail.by");
    Alex->SetGroup(2);
    Alex->SetTeam(2);
    Alex->CreatedAt(new DateTime());
    
    try {
        Alex->Save();
    }
    catch(Exception* e) {
        cout << "*********** Exception ***********" << endl;
        cout << e->what() << endl;
        cout << "********** /Exception/ **********" << endl;
    }
    
    cout << "Successfully Registration! Your id is: " << Alex->GetId() << endl;
    
    delete Alex;
    */


/* New Project
    DateTime* ea = new DateTime(), *dl = new DateTime();
    ea->AddSomeDays(14);        // 2 weeks
    dl->AddSomeDays(21);        // 3 weeks
    
    Project* project = new Project(SqlConn);
    project->Name("Модуль");
    project->Description("Сделать модуль для Joomla! 1.7");
    project->SetTeam(new Team(SqlConn, 3));
    project->TimmingPlan(5.7);
    project->SetStatus(new Status(SqlConn, 2));
    project->CreatedAt(new DateTime());
    project->ExpiredAt(ea);
    project->Deadline(dl);
    project->Priority(5);
    project->Save();
    
    delete project;
 */


/* New Task
    Project* project = new Project(SqlConn, 1);
    Status* status = new Status(SqlConn, 2);
    Task* task = new Task(SqlConn);
    
    task->Name("Написать код для модулья");
    task->Description("Очень сделать");
    task->Title("Новая задача");
    task->TimmingPlan(3.45);
    task->SetProject(project);
    task->SetUser(2);
    task->SetStatus(status);
    task->CreatedAt(new DateTime());
    task->Priority(7);
    task->Save();
    
    delete task;
    delete status;
    delete project;
 */


/* Work With WorkTime!
    WorkTime* workTime = new WorkTime(SqlConn);
    workTime->SetUser(1);
    workTime->Day(new DateTime());
    
    if(workTime->IsSet()) {
        workTime->AddTodayTime(2.5);
    }
    else {
        workTime->Hours(8);
    }
    
    try {
        workTime->Save();
    } 
    catch(Exception* e) {
        cout << e->what() << endl;
    }
    
    delete workTime;
 */


/* Report
    Report* report = new Report(SqlConn);
    report->SetTask(new Task(SqlConn, 1));
    report->SetProject(new Project(SqlConn, 1));
    report->SetReport(report->Tmpl());
    report->Hours(2.5);
    report->CreatedAt(new DateTime());
    
    try {
        report->Save();
    } 
    catch(Exception* e) {
        cout << e->what() << endl;
    }
    
    delete report;
 */


/* Wages
    Wages* wages = new Wages(SqlConn, new User(SqlConn, 1));
    cout << "Наработано " << wages->Hours() << " часов" << endl;
    cout << "Заработано " << wages->GetWagesWithPremium() << " доллоров" << endl;
    delete wages;
 */