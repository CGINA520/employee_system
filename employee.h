#pragma once
#include <iostream>
#include "Worker.h"
using namespace std;

class Employee :public Worker
{
public:
	Employee(int id, string name, int deid);

	//��ʾ������Ϣ��
	virtual void show_inf();

	//��ȡ��λ���ƣ�
	virtual string get_dename();


};
