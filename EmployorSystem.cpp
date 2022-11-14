#include <iostream>
#include "WorkerManager.h"
using namespace std;



int main()
{
    WorkerManager wm;
    int choice = 0;
    while (true)
    {
        wm.show_menu();   //��ӡ�˵�
        cout << "����ѡ������Ҫ�Ĺ���" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0:          //�˳�����ϵͳ
            wm.exit_system();
            break;
        case 1:          //���ְ����Ϣ
            wm.add_emp();
            break;
        case 2:          //��ʾԱ����Ϣ
            wm.show_emp();
            break;
        case 3:          //ɾ����ְԱ��
            wm.del_emp();
            break;
        case 4:          //�޸�Ա����Ϣ
            wm.mod_emp();
            break;
        case 5:          //����ְ����Ϣ
            wm.find_emp();
            break;
        case 6:          //��������
            wm.sort_emp();
            break;
        case 7:          //���ְ����Ϣ
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