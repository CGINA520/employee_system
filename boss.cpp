#include "boss.h"

Boss::Boss(int id, string name, int depid)
{
	this->m_Id = id;
	this->m_Name = name;
	this->DepId = depid;
}

void Boss::show_inf()
{
	cout << "职工编号：  " << this->m_Id
		<< "\t职工姓名:  " << this->m_Name
		<< "\t职工岗位:  " << this->get_dename()
		<< "\t岗位职责:  " << "管理公司所有的事物 " << endl;
}

string Boss::get_dename()
{
	return string("老板");
}