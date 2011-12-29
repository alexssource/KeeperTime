/* 
 * File:   Menu.h
 * Author: alex
 *
 * Created on December 26, 2011, 3:06 PM
 */

#ifndef MENU_H
#define	MENU_H

#include <iostream>
#include <string>
#include <vector>
#include "SqlConnector.h"
#include "User.h"
#include "Project.h"
#include "Status.h"
#include "NumberToStringConverter.h"
#include "Report.h"
#include <time.h>

using namespace std;

class Menu
{
protected:
    SqlConnector* connector;
    User* user;
    DateTime* timeStart;
    int workedtime;   // затр. время в секундах - испся как промежуточный результат
    
    void ShowMenu();
    void EnterLogin();
    void ShowStatuses();
    
    bool MenuManager();
    void ManagerShowProjects();
    void ManagerShowUsers();
    void ManagerShowActiveTasks();
    void ManagerAddProject();
    void ManagerAddTask();
    void ManagerAddUser();
    void ManagerShowReports();
    
    bool MenuUser();
    void UserShowProjects();
    void UserShowActiveTasks();
    void UserShowWorkedTime();
    void UserChangeStatusTask();
    
public:
    Menu(SqlConnector* const conn);
    ~Menu();
};

#endif	/* MENU_H */

