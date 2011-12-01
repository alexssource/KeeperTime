#include "../header/CommentNews.h"

CommentNews::CommentNews(): Comment() { }
CommentNews::CommentNews(int id): Comment(id) { }
CommentNews::~CommentNews() { }

CommentNews CommentNews::Retrieve(SqlConnector conn)
{
    std::cout << "Cap for Retrieve" << std::endl;
    return this;
}

bool CommentNews::CreateRecord(SqlConnector conn)
{
    std::cout << "Cap for CreateRecord" << std::endl;
}

bool CommentNews::UpdateRecord(SqlConnector conn)
{
    std::cout << "Cap for UpdateRecord" << std::endl;
}
