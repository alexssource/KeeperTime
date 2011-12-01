#include "../header/CommentStatus.h"

CommentStatus::CommentStatus(): Comment() { }
CommentStatus::CommentStatus(int id): Comment(id) { }
CommentStatus::~CommentStatus() { }

CommentStatus CommentStatus::Retrieve(SqlConnector conn)
{
    std::cout << "Cap for Retrieve" << std::endl;
    return this;
}

bool CommentStatus::CreateRecord(SqlConnector conn)
{
    std::cout << "Cap for CreateRecord" << std::endl;
}

bool CommentStatus::UpdateRecord(SqlConnector conn)
{
    std::cout << "Cap for UpdateRecord" << std::endl;
}