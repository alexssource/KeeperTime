#include "../header/Comment.h"

Comment::Comment() { this->parent = NULL; }

Comment::Comment(User user, Comment* parent, string comment, DateTime datetime): Comment()
{
    SetUser(user);
    SetParent(parent);
    SetComment(comment);
    SetDatetime(datetime);
}