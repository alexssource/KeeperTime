/* 
 * File:   DateTime.cpp
 * Author: alex
 * 
 * Created on December 19, 2011, 1:12 AM
 */

#include "../header/DateTime.h"

void DateTime::Initialize(int d, int m, int y, int h, int mins, int s)
{
    this->day = d;
    this->hour = h;
    this->minute = mins;
    this->month = m;
    this->seconds = s;
    this->year = y;
}

DateTime::DateTime()
{
    this->Timestamp(time(NULL));
    this->TimestampToDate();
}

DateTime::DateTime(int timestamp)
{
    this->Timestamp(timestamp);
    this->TimestampToDate();
}

DateTime::DateTime(int year, int month, int day, int hour, int minute, int seconds)
{
    this->Initialize(day, month, year, hour, minute, seconds);
    this->DateToTimestamp();
}


string DateTime::GetDMY() const
{
    string time;
    stringstream ss;
    
    ss << Day() << "." << Month() << "." << Year();
    return ss.str();
}

string DateTime::ToString() const
{
    string time;
    stringstream ss;

    ss << GetDMY() << " " << Hour() << ":" << Minute() << ":" << Seconds();
    return ss.str();
}


void DateTime::TimestampToDate()
{
    tm* stime;
    time_t tmsp = this->Timestamp();
    stime = localtime(&tmsp);
    
    this->Initialize(stime->tm_mday, stime->tm_mon + 1, stime->tm_year + 1900,
            stime->tm_hour, stime->tm_min, stime->tm_sec);
}


void DateTime::DateToTimestamp()
{
    tm* stime = new tm();
    time_t timestamp;
    
    stime->tm_year = this->year - 1900;
    stime->tm_mon = this->month - 1;
    stime->tm_mday = this->day;
    stime->tm_hour = this->hour;
    stime->tm_min = this->minute;
    stime->tm_sec = this->seconds;
    
    timestamp = mktime(stime);
    this->Timestamp(timestamp);
}


void DateTime::AddSomeDays(int days)
{
    this->Timestamp(this->Timestamp() + days*24*60*60);
    this->TimestampToDate();
}