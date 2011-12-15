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

using namespace std;

int main()
{
    string sql;
    MYSQL_RES* mysql_result = NULL;
    MYSQL_ROW sqlrow;
    SqlConnector* SqlConn;
    
    try {
        SqlConn = new SqlConnector("localhost", "keepertime", "KeeperTime", "KeeperTime");
    }
    catch(Exception* e) {
        cout << e->what() << endl;
        delete SqlConn;
        return e->Code();
    }
    
    sql = "SELECT * FROM `Group`";
    
    try {
        mysql_result = SqlConn->Query(sql, SELECT);
    }
    
    catch(MySQLRecordNotFound* rnf) {
        cout << rnf->what() << endl;
    }
    
    /*
    while(sqlrow = mysql_fetch_row(mysql_result)) {
        cout << sqlrow << " ";
    } */
    
    MYSQL* conn = &(SqlConn->GetConnectoin());
    for(int count = 0; count < mysql_field_count(conn); count++) {
        cout << sqlrow[count] << " ";
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