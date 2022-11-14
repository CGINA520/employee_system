#include "employee.h"


Employee::Employee(int id, string name, int depid)
{
	this->m_Id = id;
	this->m_Name = name;
	this->DepId = depid;
}

void Employee::show_inf()
{
	cout << "职工编号：  " << this->m_Id
		<< "\t职工姓名:  " << this->m_Name
		<< "\t职工岗位:  " << this->get_dename()
		<< "\t岗位职责:  " << "完成经理交给的任务 " << endl;
}

string Employee::get_dename()
{
	return (string)"员工";
}