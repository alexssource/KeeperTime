#include "../header/Comment.h"

Comment::Comment(): BaseRecord() { this->parent = NULL; }
Comment::Comment(int id): BaseRecord(id) { this->parent = NULL; }
Comment::~Comment() { this->parent = NULL; }