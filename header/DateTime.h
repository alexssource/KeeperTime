/* 
 * File:   DateTime.h
 * Author: alex
 *
 * Created on December 19, 2011, 1:12 AM
 */

#ifndef DATETIME_H
#define	DATETIME_H

#include <time.h>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class DateTime
{
private:
    int day;
    int month;
    int year;
    int hour;
    int minute;
    int seconds;
    int timestamp;
    
    void Initialize(int d, int m, int y, int h, int mins, int s);
    
public:
    DateTime();
    DateTime(int timestamp);
    DateTime(int year, int month, int day = 1, int hour = 0, int minute = 0, int seconds = 0);
    DateTime(const DateTime& orig) { };
    virtual ~DateTime() { };
    
    string GetDMY() const;
    string ToString() const;
    void AddSomeDays(int days);

    void TimestampToDate();
    void DateToTimestamp();
    
    
    // properties
public:
    int Day() const { return this->day; }
    void Day(int d) { this->day = d; }
    int Month() const { return this->month; }
    void Month(int t) { this->month = t; }
    int Year() const { return this->year; }
    void Year(int t) { this->year = t; }
    int Hour() const { return this->hour; }
    void Hour(int t) { this->hour = t; }
    int Minute() const { return this->minute; }
    void Minute(int t) { this->minute = t; }
    int Seconds() const { return this->seconds; }
    void Seconds(int t) { this->seconds = t; }
    int Timestamp() const { return this->timestamp; }
    void Timestamp(int t) { this->timestamp = t; }
};

#endif	/* DATETIME_H */

