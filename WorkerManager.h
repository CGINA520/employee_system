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

    //�����ļ�
    void save();

    //ͳ������
    int get_num();

    //��ʼ��
    void init_emp();

    ~WorkerManager();

    //���ݣ�
    //��¼ְ������
    int m_empnum;

    //ְ������ָ��
    Worker** m_emparry;

    //�ж��ļ��Ƿ����
    bool file_empty;
};