#pragma once
#include <iostream>
#include <string>
using namespace std;

//�������Ա����
class Worker
{
public:
	//��ʾ������Ϣ��
	virtual void show_inf() = 0;

	//��ȡ��λ���ƣ�
	virtual string get_dename() = 0;

	//Ա����ţ�
	int m_Id;

	//Ա��������
	string m_Name;

	//���ű�ţ�
	int DepId;
};
