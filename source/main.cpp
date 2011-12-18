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
#include "../header/ERROR_CODES.h"
#include "../header/SqlConnector.h"
#include "../header/Group.h"
#include "../header/BaseRecord.h"
#include <vector>

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
    
    Group* group = new Group(SqlConn);
    groups = group->RetrieveTableRecords();
    for(int i = 0; i < groups.size(); i++) {
        cout << "Group: " << ((Group*)groups[i])->Name() << endl;
    }
  
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