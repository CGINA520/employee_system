#pragma once
#include <iostream>
#include "Worker.h"
using namespace std;

class Boss:public Worker
{
public:
	Boss(int id, string name, int depid);

	//��ʾ������Ϣ��
	virtual void show_inf();

	//��ȡ��λ���ƣ�
	virtual string get_dename();
};
