#include "../header/CommentReport.h"

CommentReport::CommentReport(): Comment() { }
CommentReport::CommentReport(int id): Comment(id) { }
CommentReport::~CommentReport() { }

CommentReport CommentReport::Retrieve(int id)
{
    std::cout << "Cap for Retrieve" << std::endl;
    return this;
}

bool CommentReport::CreateRecord()
{
    std::cout << "Cap for CreateRecord" << std::endl;
}

bool CommentReport::UpdateRecord()
{
    std::cout << "Cap for UpdateRecord" << std::endl;
}
