#include "manager.h"

Manager::Manager(int id, string name, int depid)
{
	this->m_Id = id;
	this->m_Name = name;
	this->DepId = depid;
}
void Manager::show_inf()
{
	cout << "ְ����ţ�  " << this->m_Id
		<< "\tְ������:  " << this->m_Name
		<< "\tְ����λ:  " << this->get_dename()
		<< "\t��λְ��:  " << "����ϰ彻�������񣬲��·���Ա��"<<endl;
}

string Manager::get_dename()
{
	return (string)"����";
}