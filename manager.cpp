#include "manager.h"

Manager::Manager(int id, string name, int depid)
{
	this->m_Id = id;
	this->m_Name = name;
	this->DepId = depid;
}
void Manager::show_inf()
{
	cout << "职工编号：  " << this->m_Id
		<< "\t职工姓名:  " << this->m_Name
		<< "\t职工岗位:  " << this->get_dename()
		<< "\t岗位职责:  " << "完成老板交给的任务，并下发给员工"<<endl;
}

string Manager::get_dename()
{
	return (string)"经理";
}