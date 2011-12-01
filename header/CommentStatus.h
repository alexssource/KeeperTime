/* 
 * File:   CommentStatus.h
 * Author: Alex Kozlov <alexssource@gmail.com>
 *
 * Created on December 1, 2011, 9:55 AM
 */

#ifndef COMMENTSTATUS_H
#define	COMMENTSTATUS_H

#include <iostream>
#include "Comment.h"

class CommentStatus: public Comment
{
private:
    Status status;
    
public:
    CommentStatus();
    CommentStatus(int id);
    virtual ~CommentStatus();
    virtual CommentStatus Retrieve(int id);
    virtual bool UpdateRecord();
    virtual bool CreateRecord();
    
    
    // Properties:
    Status GetStatus() { return this->status; }
    void SetStatus(Status status) { this->status = status; }
};

#endif	/* COMMENTSTATUS_H */

