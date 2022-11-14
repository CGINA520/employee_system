#pragma once
#include <iostream>
#include <string>
using namespace std;

//构造抽象员工类
class Worker
{
public:
	//显示个人信息：
	virtual void show_inf() = 0;

	//获取岗位名称：
	virtual string get_dename() = 0;

	//员工编号：
	int m_Id;

	//员工姓名：
	string m_Name;

	//部门编号：
	int DepId;
};
