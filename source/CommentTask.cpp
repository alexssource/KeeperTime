#include "../header/CommentTask.h"

CommentTask::CommentTask(): Comment() { }
CommentTask::CommentTask(int id): Comment(id) { }
CommentTask::~CommentTask() { }

CommentTask CommentTask::Retrieve(SqlConnector conn)
{
    std::cout << "Cap for Retrieve" << std::endl;
    return this;
}

bool CommentTask::CreateRecord(SqlConnector conn)
{
    std::cout << "Cap for CreateRecord" << std::endl;
}

bool CommentTask::UpdateRecord(SqlConnector conn)
{
    std::cout << "Cap for UpdateRecord" << std::endl;
}
