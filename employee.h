#pragma once
#include <iostream>
#include "Worker.h"
using namespace std;

class Employee :public Worker
{
public:
	Employee(int id, string name, int deid);

	//显示个人信息：
	virtual void show_inf();

	//获取岗位名称：
	virtual string get_dename();


};
