/* 
 * File:   Menu.cpp
 * Author: alex
 * 
 * Created on December 26, 2011, 3:06 PM
 */

#include "../header/Menu.h"
#include "header/Task.h"

Menu::Menu(SqlConnector* const conn): connector(conn) { this->user = NULL; this->ShowMenu(); }
Menu::~Menu() { delete this->user; }

void Menu::ShowMenu()
{
    cout << "Menu:" << endl;
    
    while(this->user == NULL) {
        this->EnterLogin();
    }
    
    if(this->user->GetGroup()->Name() == "manager") {
        while(this->MenuManager()) { }
    }
    else if(this->user->GetGroup()->Name() == "user") {
        while(this->MenuUser()) { }
    }
    else {
        cout << "Your group isn't find" << endl;
    }
}

void Menu::EnterLogin()
{
    string login;
    string password;
    User* user;
    
    cout << "Enter your Login: ";
    cin >> login;
    cout << "Enter password for '" << login << "': ";
    cin >> password;
    cout << "\n";
    
    user = new User(this->connector);
    user->Login(login);
    user->Password(password);
    
    try {
        user->RetrieveByLoginPass();
    }
    catch(Exception* e) {
        cout << e->what() << endl;
        return;
    }

    this->user = user;
    this->timeStart = new DateTime();
}


void Menu::ShowStatuses()
{
    Status* status = new Status(this->connector);
    vector<BaseRecord*> statuses;
    
    statuses = status->RetrieveTableRecords();
    
    for(int i = 0; i < statuses.size(); i++) {
        cout << "- " << statuses[i]->GetId() << ": " << ((Status*)statuses[i])->Name() << endl;
    }
    
    delete status;
}


bool Menu::MenuManager()
{
    int choice = 0;
    
    do {
        cout << "Manager:" << endl;
        cout << "1. Show Projects" << endl;
        cout << "2. Show Users in my team" << endl;
        cout << "3. Show Active Tasks" << endl;
        cout << "4. Add new project" << endl;
        cout << "5. Add new task" << endl;
        cout << "6. Add new user" << endl;
        cout << "7. Просмотр отчетов по проектам" << endl;
        cout << "0. Exit" << endl;

        cout << "Выберите действие: ";
        cin >> choice;
    } while((choice < 1) && choice > 7);
    
    switch(choice) {
        case 1:
            this->ManagerShowProjects();
            return true;
            break;
            
        case 2:
            this->ManagerShowUsers();
            return true;
            break;
            
        case 3:
            this->ManagerShowActiveTasks();
            return true;
            break;
            
        case 4:
            this->ManagerAddProject();
            return true;
            break;
            
        case 5:
            this->ManagerAddTask();
            return true;
            break;
            
        case 6:
            this->ManagerAddUser();
            return true;
            break;
            
        case 7:
            this->ManagerShowReports();
            return true;
            break;
            
        case 0:
            return false;
            break;
    }
}

void Menu::ManagerShowProjects()
{
    Project* project = new Project(this->connector);
    vector<BaseRecord *> projects;
    string where = " WHERE `team` = " + NumberToStringConverter<int>::Convert(this->user->GetTeam()->GetId()) 
            + " ORDER BY `id` DESC, `status` ASC";
    
    try {
        projects = project->RetrieveTableRecords(where);
    }
    catch(Exception* e) {
        cout << e->what() << endl;
    }
    
    if(projects[0]->GetId()) cout << "Проекты для команды " << ((Project *)projects[0])->GetTeam()->Name() << endl;
    
    for(int i = 0; i < projects.size(); i++) {
        cout << "- " << ((Project *)projects[i])->GetId() << ": " << ((Project *)projects[i])->Name() << endl;
        cout << ((Project *)projects[i])->Description() << endl;
        cout << "Статус: " << ((Project *)projects[i])->GetStatus()->Name() << endl;
        cout << "Приоритет: " << ((Project *)projects[i])->Priority() << endl;
        cout << "Расчётное время: " << ((Project *)projects[i])->TimmingPlan() << " часов" << endl;
        cout << "Дата созданиия: " << ((Project *)projects[i])->CreatedAt()->ToString() << endl;
        cout << "Действителен до: " << ((Project *)projects[i])->ExpiredAt()->ToString() << endl;
        cout << "Deadline: " << ((Project *)projects[i])->Deadline()->ToString() << "\n" << endl;
    }
}

void Menu::ManagerShowUsers()
{
    vector<BaseRecord *> users;
    string where = " WHERE `team` = " + NumberToStringConverter<int>::Convert(this->user->GetTeam()->GetId()) 
            + " ORDER BY `id` ASC";
    
    try {
        users = this->user->RetrieveTableRecords(where);
    }
    catch(Exception* e) {
        cout << e->what() << endl;
    }
    
    if(users[0]->GetId()) cout << "Пользователи команды " << ((User *)users[0])->GetTeam()->Name() << endl;
    
    for(int i = 0; i < users.size(); i++) {
        cout << "- " << ((User*)users[i])->GetId() << ": " << ((User*)users[i])->Name() << " "
                << ((User*)users[i])->Surname() << " (" << ((User*)users[i])->Login() << ")" << endl;
        cout << "Email:\t" << ((User*)users[i])->Email() << endl;
        cout << "Группа:\t" << ((User*)users[i])->GetGroup()->Name() << endl;
        cout << "Создан:\t" << ((User*)users[i])->CreatedAt()->ToString() << endl;
        cout << "Часовая тарифная ставка:\t" << ((User*)users[i])->Wage() << "$\\час\n" << endl;
    }
}


void Menu::ManagerShowActiveTasks()
{
    Task* task = new Task(this->connector);
    vector<BaseRecord *> tasks;
    string where = " INNER JOIN `Project` p ON t.project = p.id WHERE p.`team` = " + NumberToStringConverter<int>::Convert(this->user->GetTeam()->GetId()) 
            + " ORDER BY t.`id` DESC, t.`project` ASC, t.`status` ASC";
    
    try {
        tasks = task->RetrieveTableRecords(where);
    }
    catch(Exception* e) {
        cout << e->what() << endl;
    }
    
    if(tasks[0]->GetId()) cout << "Задачи команды " << ((Task *)tasks[0])->GetProject()->GetTeam()->Name() << endl;
    
    for(int i = 0; i < tasks.size(); i++) {
        cout << "- " << ((Task *)tasks[0])->GetId() << ": " << ((Task *)tasks[0])->Name() << endl;
        cout << ((Task *)tasks[0])->Description() << endl;
        cout << "Проект: " << ((Task *)tasks[0])->GetProject()->Name() << endl;
        cout << "Исполнитель: " << ((Task *)tasks[0])->GetUser()->Name() << " " 
                << ((Task *)tasks[0])->GetUser()->Surname() << " (" 
                << ((Task *)tasks[0])->GetUser()->Login() << ")" << endl;
        cout << "Статус: " << ((Task *)tasks[0])->GetStatus()->Name() << endl;
        cout << "Дата создания: " << ((Task *)tasks[0])->CreatedAt()->ToString() << endl;
        cout << "Приоритет: " << ((Task *)tasks[0])->Priority() << "\n" << endl;
    }
}


void Menu::ManagerShowReports()
{
    Report* report = new Report(this->connector);
    vector<BaseRecord *> reports;
    string where;
    int pid;
    
    cout << "Выберите проект, по которому хотите посмотреть отчеты, и запомните его id" << endl;
    this->ManagerShowProjects();
    cout << "Введите id проекта: ";
    cin >> pid;
    
    where = " WHERE `project` = " + NumberToStringConverter<int>::Convert(pid);
    
    try {
        reports = report->RetrieveTableRecords(where);
    }
    catch(Exception* e) {
        cout << e->what() << endl;
    }
    
    if(reports[0]->GetId()) cout << "Отчеты по проекту " << ((Report*)reports[0])->GetProject()->Name() << ":" << endl;
    
    for(int i = 0; i < reports.size(); i++) {
        cout << "- " << reports[i]->GetId() << ": From User:" 
                << ((Report*)reports[0])->GetTask()->GetUser()->Name() << " "
                << ((Report*)reports[0])->GetTask()->GetUser()->Surname() << " ("
                << ((Report*)reports[0])->GetTask()->GetUser()->Login() << ")" << endl;
        cout << "Задача: [" << ((Report*)reports[0])->GetTask()->GetId() << "] "
                << ((Report*)reports[0])->GetTask()->Name() << endl;
        cout << "Проект: [" << ((Report*)reports[0])->GetProject()->GetId() << "] "
                << ((Report*)reports[0])->GetProject()->Name() << endl;
        cout << ((Report*)reports[0])->GetReport() << endl;
        cout << "Затрачено времени на выполнение проекта: " << ((Report*)reports[0])->Hours() << " часов" << endl;
        cout << "Дата создания отчета: " << ((Report*)reports[0])->CreatedAt()->ToString() << "\n" << endl;
    }
}


void Menu::ManagerAddProject()
{
    Project* project = new Project(this->connector);
    string name, description;
    //unsigned int team, status, created, expired, deadline
    int priority, ed, em, ey, dd, dm, dy;
    float timming_plan;
    
    cout << "Введите название проекта: ";
    cin >> name;
    cout << "Введите описание проекта:" << endl;
    cin >> description;
    cout << "Введите дату, до которой действителен проект: " << endl;
    cout << "\tДень(1-31): ";
    cin >> ed;
    cout << "\tМесяц(1-12): ";
    cin >> em;
    cout << "\tГод(1900 - 2900): ";
    cin >> ey;
    cout << "Введите Deadline-дату: " << endl;
    cout << "\tДень(1-31): ";
    cin >> dd;
    cout << "\tМесяц(1-12): ";
    cin >> dm;
    cout << "\tГод(1900 - 2900): ";
    cin >> dy;
    cout << "Введите приоритет (1-7): ";
    cin >> priority;
    cout << "Введите планируемое на разработку время: ";
    cin >> timming_plan;
    
    project->Name(name);
    project->Description(description);
    project->SetTeam(this->user->GetTeam());
    project->TimmingPlan(timming_plan);
    project->SetStatus(new Status(this->connector, 2));
    project->CreatedAt(new DateTime());
    project->ExpiredAt(new DateTime(ey, em, ed, 0, 0, 0));
    project->Deadline(new DateTime(dy, dm, dd, 0, 0, 0));
    project->Priority(priority);
    project->Save();
    
    if(project->GetId() != 0) {
        cout << "Проект успешно сохранен!\nId проекта: " << project->GetId() << endl;
    }
    else {
        cout << "Возникла ошибка при сохранении проекта" << endl;
    }
    
    delete project;
}


void Menu::ManagerAddTask()
{
    Task* task = new Task(this->connector);
    string name, title, description;
    float timming_plan;
    int project, user, status = 2, priority;
    
    cout << "Введите название задачи: ";
    cin >> name;
    cout << "Заголовок задачи: ";
    cin >> title;
    cout << "Описание задачи: ";
    cin >> description;
    cout << "Найдите проект, соответствующий задаче, и запомните его id:" << endl;
    this->ManagerShowProjects();
    cout << "Введите id проекта: ";
    cin >> project;
    cout << "Найдите пользователя, которому хотите поручить данную задачу, и запомните его id:" << endl;
    this->ManagerShowUsers();
    cout << "Введите id пользователя: ";
    cin >> user;
    cout << "Введите планируемое время выполнения задачи: ";
    cin >> timming_plan;
    cout << "Введите приоритет задачи: ";
    cin >> priority;
    
    task->Name(name);
    task->Title(title);
    task->Description(description);
    task->TimmingPlan(timming_plan);
    task->SetProject(project);
    task->SetUser(user);
    task->SetStatus(status);
    task->CreatedAt(new DateTime());
    task->Priority(priority);
    task->Save();
    
    if(task->GetId() != 0) {
        cout << "Задача успешно сохранена!\nId задачи: " << task->GetId() << endl;
    }
    else {
        cout << "Возникла ошибка при сохранении задачи" << endl;
    }
    
    delete task;
}


void Menu::ManagerAddUser()
{
    User* user = new User(this->connector);
    string name, surname, login, password, email;
    int group = 1, wage;
    
    cout << "Введите имя: " << endl;
    cin >> name;
    cout << "Фамилия: " << endl;
    cin >> surname;
    cout << "Логин: " << endl;
    cin >> login;
    cout << "Пароль: " << endl;
    cin >> password;
    cout << "Email: " << endl;
    cin >> email;
    cout << "Часовая тарифная ставка: " << endl;
    cin >> wage;
    
    user->Name(name);
    user->Surname(surname);
    user->Login(login);
    user->Password(password);
    user->Email(email);
    user->SetGroup(group);
    user->SetTeam(this->user->GetTeam());
    user->Wage(wage);
    user->CreatedAt(new DateTime());
    user->Save();
    
    if(user->GetId() != 0) {
        cout << "Пользователь успешно сохранен!\nId юзера: " << user->GetId() << endl;
    }
    else {
        cout << "Возникла ошибка при сохранении пользователя" << endl;
    }
    
    //delete user;
}



bool Menu::MenuUser()
{
    int choice = 0;
    
    do {
        cout << "User:" << endl;
        cout << "1. Show Projects" << endl;
        cout << "2. Show Active Tasks" << endl;
        cout << "3. Просмотреть время работы" << endl;
        cout << "4. Изменить статус задачи" << endl;
        cout << "0. Exit" << endl;

        cout << "Выберите действие: ";
        cin >> choice;
    } while((choice < 1) && choice > 4);
    
    switch(choice) {
        case 1:
            this->UserShowProjects();
            return true;
            break;

        case 2:
            this->UserShowActiveTasks();
            return true;
            break;
            
        case 3:
            this->UserShowWorkedTime();
            return true;
            break;
            
        case 4:
            this->UserChangeStatusTask();
            return true;
            break;
            
        case 0:
            return false;
            break;
    }
}


void Menu::UserShowProjects()
{
    this->ManagerShowProjects();
}

void Menu::UserShowActiveTasks()
{
    Task* task = new Task(this->connector);
    vector<BaseRecord *> tasks;
    string where = " INNER JOIN `Project` p ON t.project = p.id WHERE p.`team` = " 
            + NumberToStringConverter<int>::Convert(this->user->GetTeam()->GetId()) 
            + " AND `user` = " + NumberToStringConverter<int>::Convert(this->user->GetId())
            + " ORDER BY t.`id` DESC, t.`project` ASC, t.`status` ASC";
    
    try {
        tasks = task->RetrieveTableRecords(where);
    }
    catch(Exception* e) {
        cout << e->what() << endl;
    }
    
    if(tasks[0]->GetId()) cout << "Задачи команды " << ((Task *)tasks[0])->GetProject()->GetTeam()->Name() << endl;
    
    for(int i = 0; i < tasks.size(); i++) {
        cout << "- " << ((Task *)tasks[0])->GetId() << ": " << ((Task *)tasks[0])->Name() << endl;
        cout << ((Task *)tasks[0])->Description() << endl;
        cout << "Проект: " << ((Task *)tasks[0])->GetProject()->Name() << endl;
        cout << "Исполнитель: " << ((Task *)tasks[0])->GetUser()->Name() << " " 
                << ((Task *)tasks[0])->GetUser()->Surname() << " (" 
                << ((Task *)tasks[0])->GetUser()->Login() << ")" << endl;
        cout << "Статус: " << ((Task *)tasks[0])->GetStatus()->Name() << endl;
        cout << "Дата создания: " << ((Task *)tasks[0])->CreatedAt()->ToString() << endl;
        cout << "Приоритет: " << ((Task *)tasks[0])->Priority() << "\n" << endl;
    }
}


void Menu::UserShowWorkedTime()
{
    DateTime* timeEnd = new DateTime();
    int deltaSeconds = timeEnd->Timestamp() - this->timeStart->Timestamp();
    float deltaHours = (float) deltaSeconds / 3600;
    
    cout << "Вы работаете " << deltaHours << " часов" << endl;
    this->workedtime = deltaSeconds;
}


void Menu::UserChangeStatusTask()
{
    int tid, sid;
    float time;
    string rep;
    Report* report = new Report(this->connector);
    Task* task;
    
    this->UserShowWorkedTime();
    cout << "Выберите задачу: " << endl;
    this->UserShowActiveTasks();
    cout << "Введите id изменяемой задачи: ";
    cin >> tid;
    cout << "Выберите новый статус: " << endl;
    this->ShowStatuses();
    cout << "Введите id нового статуса: ";
    cin >> sid;
    
    do {
        cout << "Введите время в часах, затраченное на выполнение задачи: " << endl;
        this->UserShowWorkedTime();
        cout << " -> ";
        cin >> time;
    } while(time*3600 > this->workedtime);
    
    cout << "Напишите отчет о проделанной работе:" << endl;
    cin >> rep;
    
    // не забыть сделать изменение статуса!!!
    
    task = new Task(this->connector, tid);
    task->SetStatus(sid);
    task->Save();
    cout << "Статус задачи изменен!" << endl;
    
    report->SetTask(task);
    report->SetProject(task->GetProject());
    report->SetReport(rep);
    report->Hours(time);
    report->CreatedAt(new DateTime());
    report->Tmpl(rep);
    report->Save();

    if(report->GetId() != 0) {
        cout << "Отчет успешно сохранен!\nId отчета: " << report->GetId() << endl;
        int oldtmstmp = this->timeStart->Timestamp();
        int newtmstmp = oldtmstmp + time*3600;
        this->timeStart->Timestamp(newtmstmp);
    }
    else {
        cout << "Возникла ошибка при сохранении отчета" << endl;
    }
}