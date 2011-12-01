/* 
 * File:   CommentNews.h
 * Author: Alex Kozlov <alexssource@gmail.com>
 *
 * Created on December 1, 2011, 10:27 AM
 */

#ifndef COMMENTNEWS_H
#define	COMMENTNEWS_H


#include <iostream>
#include "Comment.h"

class CommentNews: public Comment
{
private:
    News news;
    
public:
    CommentNews();
    CommentNews(int id);
    virtual ~CommentNews();
    virtual CommentNews Retrieve(int id);
    virtual bool UpdateRecord();
    virtual bool CreateRecord();
    
    
    // Properties:
    News GetNews() { return this->news; }
    void SetNews(News news) { this->news = news; }
};


#endif	/* COMMENTNEWS_H */

