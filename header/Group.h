/* 
 * File:   Group.h
 * Author: Alex Kozlov <alexssource@gmail.com>
 *
 * Created on December 1, 2011, 10:43 AM
 */

#ifndef GROUP_H
#define	GROUP_H

#include <iostream>
#include <string>
#include "BaseRecord.h"

using namespace std;

class Group: public BaseRecord
{
private:
    string name;
    bool is_manager;
    bool is_admin;
    
public:
    Group();
    Group(int id);
    virtual ~Group();
    virtual Group Retrieve(SqlConnector conn, int id);
    virtual bool UpdateRecord(SqlConnector conn);
    virtual bool CreateRecord(SqlConnector conn);
    bool CompareTo(const Group& rhs);
    
    // Properties:
    string GetName() { return this->name; }
    void SetName(string name) { this->name = name; }
    void IsManager(bool is_manager) { this->is_manager = is_manager; }
    bool IsManager() { return this->is_manager; }
    void IsAdmin(bool is_admin) { this->is_admin = is_admin; }
    bool IsAdmin() { return this->is_admin; }
};

#endif	/* GROUP_H */

