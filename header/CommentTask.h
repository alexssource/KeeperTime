/* 
 * File:   CommentTask.h
 * Author: Alex Kozlov <alexssource@gmail.com>
 *
 * Created on December 1, 2011, 10:42 AM
 */

#ifndef COMMENTTASK_H
#define	COMMENTTASK_H


#include <iostream>
#include "Comment.h"

class CommentTask: public Comment
{
private:
    Task task;
    
public:
    CommentTask();
    CommentTask(int id);
    virtual ~CommentTask();
    virtual CommentTask Retrieve(int id);
    virtual bool UpdateRecord();
    virtual bool CreateRecord();
    
    
    // Properties:
    Task GetTask() { return this->task; }
    void SetTask(Task task) { this->task = task; }
};


#endif	/* COMMENTTASK_H */

