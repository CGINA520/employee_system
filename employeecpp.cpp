#include "employee.h"


Employee::Employee(int id, string name, int depid)
{
	this->m_Id = id;
	this->m_Name = name;
	this->DepId = depid;
}

void Employee::show_inf()
{
	cout << "ְ����ţ�  " << this->m_Id
		<< "\tְ������:  " << this->m_Name
		<< "\tְ����λ:  " << this->get_dename()
		<< "\t��λְ��:  " << "��ɾ����������� " << endl;
}

string Employee::get_dename()
{
	return (string)"Ա��";
}