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
#include "../header/ERROR_CODES.h"
#include "../header/SqlConnector.h"

using namespace std;

int main()
{
    SqlConnector* SqlConn;
    
    try {
        SqlConn = new SqlConnector("localhost", "keepertime", "KeeperTime", "KeeperTime");
    }
    catch(Exception* e) {
        cout << e->what() << endl;
        delete SqlConn;
        return e->Code();
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