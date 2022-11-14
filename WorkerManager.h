#pragma once

#include <iostream>
#include <fstream>
#include "Worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;

#define FILENAME "EmpFile.txt"


class WorkerManager
{
public:
    WorkerManager();

    void show_menu();

    void exit_system();

    void add_emp();

    void show_emp();

    int is_exit(int id);

    void del_emp();

    void mod_emp();

    void find_emp();

    void sort_emp();

    void clean_file();

    //保存文件
    void save();

    //统计人数
    int get_num();

    //初始化
    void init_emp();

    ~WorkerManager();

    //数据：
    //记录职工人数
    int m_empnum;

    //职工数组指针
    Worker** m_emparry;

    //判断文件是否存在
    bool file_empty;
};