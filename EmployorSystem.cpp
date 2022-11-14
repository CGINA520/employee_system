#include <iostream>
#include "WorkerManager.h"
using namespace std;



int main()
{
    WorkerManager wm;
    int choice = 0;
    while (true)
    {
        wm.show_menu();   //打印菜单
        cout << "请您选择所需要的功能" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0:          //退出管理系统
            wm.exit_system();
            break;
        case 1:          //添加职工信息
            wm.add_emp();
            break;
        case 2:          //显示员工信息
            wm.show_emp();
            break;
        case 3:          //删除离职员工
            wm.del_emp();
            break;
        case 4:          //修改员工信息
            wm.mod_emp();
            break;
        case 5:          //查找职工信息
            wm.find_emp();
            break;
        case 6:          //快速排序
            wm.sort_emp();
            break;
        case 7:          //清空职工信息
            wm.clean_file();
            break;
        default:
            system("cls");
            break;
        }
    }
    system("pause");
    return 0;
}