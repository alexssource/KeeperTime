/* 
 * File:   CommentReport.h
 * Author: Alex Kozlov <alexssource@gmail.com>
 *
 * Created on December 1, 2011, 10:20 AM
 */

#ifndef COMMENTREPORT_H
#define	COMMENTREPORT_H

#include <iostream>
#include "Comment.h"

class CommentReport: public Comment
{
private:
    Report report;
    
public:
    CommentReport();
    CommentReport(int id);
    virtual ~CommentReport();
    virtual CommentReport Retrieve(int id);
    virtual bool UpdateRecord();
    virtual bool CreateRecord();
    
    
    // Properties:
    Report GetReport() { return this->report; }
    void SetReport(Report report) { this->report = report; }
};

#endif	/* COMMENTREPORT_H */

