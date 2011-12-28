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
#include "SqlConnector.h"
#include "User.h"

using namespace std;

class Menu
{
protected:
    SqlConnector* connector;
    User* user;
    
    void ShowMenu();
    void EnterLogin();
    
public:
    Menu(SqlConnector* const conn);
    ~Menu();
};

#endif	/* MENU_H */

