/* 
 * File:   Wages.h
 * Author: alex
 *
 * Created on December 26, 2011, 2:20 AM
 */

#ifndef WAGES_H
#define	WAGES_H

#include "SqlConnector.h"
#include "WorkTime.h"

class Wages
{
private:
    float wages;
    float premium;
    float hours;
    User* user;
    DateTime* dateStart;
    DateTime* dateEnd;
    SqlConnector* connector;
    
    void Initialize();
    void PostConstructor();
    
public:
    Wages(SqlConnector* const conn, User* const user);
    Wages(SqlConnector* const conn, User* const user, DateTime* const dateStart, DateTime* const dateEnd);
    Wages(const Wages& orig);
    virtual ~Wages();
    
    
    // Properties
    float GetWages() const { return this->wages; }
    void SetWages(float w) { this->wages = w; }
    float GetWagesWithPremium() const { return this->GetWages() + this->Premium(); }
    float Premium() const { return this->premium; }
    void Premium(float p) { this->premium = p; }
    User* GetUser() const { return this->user; }
    void SetUser(User* u) { this->user = u; }
    DateTime* DateStart() const { return this->dateStart; }
    void DateStart(DateTime* ds) { this->dateStart = ds; }
    DateTime* DateEnd() const { return this->dateEnd; }
    void DateEnd(DateTime* de) { this->dateEnd = de; }
    float Hours() const { return this->hours; }
    void Hours(float delta) { this->hours += delta; }
};

#endif	/* WAGES_H */

