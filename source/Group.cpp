#include "../header/Group.h"

Group::Group(): BaseRecord() { }
Group::Group(int id): BaseRecord(id) { }
Group::~Group() { }

Group Group::Retrieve(SqlConnector conn, int id)
{
    std::cout << "Cap for Retrieve" << std::endl;
    return this;
}

bool Group::CreateRecord(SqlConnector conn)
{
    std::cout << "Cap for CreateRecord" << std::endl;
}

bool Group::UpdateRecord(SqlConnector conn)
{
    std::cout << "Cap for UpdateRecord" << std::endl;
}

bool Group::CompareTo(const Group& rhs)
{
    return ( (this->GetName() == rhs.GetName()) && (this->GetId() == rhs.GetId()) );
}