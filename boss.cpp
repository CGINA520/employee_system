#include "boss.h"

Boss::Boss(int id, string name, int depid)
{
	this->m_Id = id;
	this->m_Name = name;
	this->DepId = depid;
}

void Boss::show_inf()
{
	cout << "ְ����ţ�  " << this->m_Id
		<< "\tְ������:  " << this->m_Name
		<< "\tְ����λ:  " << this->get_dename()
		<< "\t��λְ��:  " << "����˾���е����� " << endl;
}

string Boss::get_dename()
{
	return string("�ϰ�");
}