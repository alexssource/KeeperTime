/* 
 * File:   Menu.cpp
 * Author: alex
 * 
 * Created on December 26, 2011, 3:06 PM
 */

#include "../header/Menu.h"

Menu::Menu(SqlConnector* const conn): connector(conn) { this->user = NULL; this->ShowMenu(); }
Menu::~Menu() { delete this->user; }

void Menu::ShowMenu()
{
    cout << "Menu:" << endl;
    
    while(this->user == NULL) {
        this->EnterLogin();
    }
    
    cout << "Your Group is: " << this->user->GetGroup()->Name() << endl;
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
}