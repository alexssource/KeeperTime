/* 
 * File:   Comment.h
 * Author: Alex Kozlov <alexssource@gmail.com>
 *
 * Created on November 29, 2011, 5:28 AM
 */

#ifndef COMMENT_H
#define	COMMENT_H

#include <string>
#include <stdlib.h>

using namespace std;

class Comment
{
protected:
    int id;     // readonly field
    User user;
    Comment* parent;
    string comment;
    DateTime datetime;
    
public:
    // Properties:
    int GetId() const { return this->id; }
    void SetUser(User user) { this->user = user; }
    User GetUser() const { return this->user; }
    void SetParent(Comment* parent) { this->parent = parent; }
    Comment* GetParent() const { return this->parent; }
    void SetComment(string comment) { this->comment = comment; }
    string GetComment() const { return this->comment; }
    void SetDatetime(DateTime datetime) { this->datetime = datetime; }
    DateTime GetDateTime() const { return this->datetime; }
    
    
    // Methods:
    
    /**
     * Default constructor
     */
    Comment();
    

    /**
     * Overloaded default constructor
     * @param user - the instance of user, who created a comment
     * @param parent - the pointer for parent comment, default is NULL
     * @param comment - new user's comment
     * @param datetime - the instance of DateTime object
     */
    Comment(User user, Comment* parent = NULL, string comment, DateTime datetime);
    
    
    
    /**
     * Virtual Abstract method for create new comment and sumbit it to database
     * @param parent_id - the parent of current comment, default is 0
     * @return bool - true if success
     */
    virtual bool CreateComment(int parent_id = 0) = 0;
    
    
    /**
     * Virtual Abstract method for retrieve the comment from database by its id
     * @param comment_id - the identifier of comment
     * @return Comment - the instance of Comment
     */
    virtual Comment RetrieveComment(int comment_id) = 0;
};

#endif	/* COMMENT_H */

