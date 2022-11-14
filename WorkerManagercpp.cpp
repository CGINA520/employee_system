#include "WorkerManager.h"

WorkerManager::WorkerManager()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    //1.�ļ�������
    if (!ifs.is_open())
    {
        //cout << "�ļ��򲻿�" << endl;
        this->m_empnum = 0;
        this->m_emparry = NULL;
        this->file_empty = true;
        ifs.close();
        return;
    }
    //2.�ļ����ڵ�Ϊ��
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        //cout << "�ļ�Ϊ��" << endl;
        this->m_empnum = 0;
        this->m_emparry = NULL;
        this->file_empty = true;
        ifs.close();
        return;
    }
    //3.�ļ�������������
    int num = this->get_num();
   // cout << "�ļ�����������ְ������Ϊ: " << num << endl;
    this->m_empnum = num;

    //���ٿռ�
    this->m_emparry = new Worker * [this->m_empnum];
    //��ʼ��
    this->init_emp();
}

void WorkerManager::show_menu()
{
    cout << "----------------------------------------" << endl;
    cout << "--------  ��ӭʹ��ְ������ϵͳ  --------" << endl;
    cout << "-----------  0.�˳�����ϵͳ  -----------" << endl;
    cout << "-----------  1.����ְ����Ϣ  -----------" << endl;
    cout << "-----------  2.��ʾְ����Ϣ  -----------" << endl;
    cout << "-----------  3.ɾ����ְְ��  -----------" << endl;
    cout << "-----------  4.�޸�ְ����Ϣ  -----------" << endl;
    cout << "-----------  5.����ְ����Ϣ  -----------" << endl;
    cout << "-----------  6.���ձ������  -----------" << endl;
    cout << "-----------  7.��������ĵ�  -----------" << endl;
    cout << "----------------------------------------" << endl;
    cout << endl;
}

void WorkerManager::exit_system()
{
    cout << "��ӭ�´�ʹ��" << endl;
    system("pause");
    exit(0);
}

void WorkerManager::add_emp()
{
    cout << "���������ְ������" << endl;
    int addnum = 0;
    cin >> addnum;
    if (addnum > 0)
    {
        //��Ӽ����¿ռ�Ĵ�С
        int newsize = this->m_empnum + addnum;
        Worker** newspace = new Worker * [newsize];

        //�ж�ԭ�������з�������
        if (this->m_emparry != NULL)
        {
            for (int i = 0; i < this->m_empnum; i++)
            {
                newspace[i] = this->m_emparry[i];
            }
        }
        for (int i = 0; i < addnum; i++)
        {
            int id;      // ְ�����
            string name; // ְ������
            int dselect; // ְ������
            cout << "�������" << i + 1 << "��ְ�����" << endl;
            cin >> id;
            cout << "�������" << i + 1 << "��ְ������" << endl;
            cin >> name;
            cout << "�������" << i + 1 << "��ְ������" << endl;
            cout << "1.��ְͨ��" << endl;
            cout << "2.����" << endl;
            cout << "3.�ϰ�" << endl;
            cin >> dselect;
            Worker* worker = NULL;
            switch (dselect)
            {
            case 1:
                worker = new Employee(id, name, 1);
                break;
            case 2:
                worker = new Manager(id, name, 2);
                break;
            case 3:
                worker = new Boss(id, name, 3);
                break;
            }
            //��������ְ�����浽������
            newspace[this->m_empnum + i] = worker;
        }
        //�ͷ�ԭ�еĿռ�
        delete[]this->m_emparry;
        //�����¿ռ��ָ��
        this->m_emparry = newspace;
        //�����µ�ְ������
        this->m_empnum = newsize;
        //��ʾ��ӳɹ�
        //�ļ���Ϊ�ձ�־
        this->file_empty = false;
        cout << "�ɹ����" << addnum << "������ְ��" << endl;
        //�����ļ�
        this->save();
    }
    else
    {
        cout << "�������������" << endl;
    }
}

void WorkerManager::show_emp()
{
    if (this->file_empty)
    {
        cout << "�ļ������ڼ�¼Ϊ��" << endl;
    }
    else
    {
        for (int i = 0; i < this->m_empnum; i++)
        {
            //���ö�̬�ӿ�
            this->m_emparry[i]->show_inf();
        }
    }
    system("pause");
    system("cls");
}

int WorkerManager::is_exit(int id)
{
    int index = -1;
    for (int i = 0; i < this->m_empnum; i++)
    {
        if (this->m_emparry[i]->m_Id == id)
        {
            index = i;
        }
    }
    return index;
}

void WorkerManager::del_emp()
{
    if (this->file_empty)
    {
        cout << "�ļ������ڻ��¼Ϊ��" << endl;
    }
    else
    {
        cout << "������Ҫɾ����ְ�����" << endl;
        int id;
        cin >> id;
        int index = 0;
        index = this->is_exit(id);
        if (index != -1)
        {
            for (int i = index; i < this->m_empnum - 1; i++)
            {
                this->m_emparry[i] = this->m_emparry[i + 1];
            }
            this->m_empnum--;
            this->save();
            cout << "ɾ���ɹ�" << endl;
        }
        else
        {
            cout << "�Ҳ���Ҫɾ����ְ�����" << endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::mod_emp()
{
    if (this->file_empty)
    {
        cout << "�ļ������ڻ��¼Ϊ��" << endl;
    }
    else
    {
        cout << "������Ҫ�޸ĵ�ְ�����" << endl;
        int id;
        cin >> id;
        int ret = this->is_exit(id);
        if (ret != -1)
        {
            delete this->m_emparry[ret];
            int newid;
            string newname;
            int newselect;

            cout << "�鵽" << id << "��Ա��,�������µ�ְ����" << endl;
            cin >> newid;
            cout << "�鵽" << id << "��Ա��,�������µ�����" << endl;
            cin >> newname;
            cout << "�鵽" << id << "��Ա��,�������λ" << endl;
            cout << "1.��ְͨ��" << endl;
            cout << "2.����" << endl;
            cout << "3.�ϰ�" << endl;
            cin >> newselect;

            Worker* worker = NULL;
            switch (newselect)
            {
            case 1:
                worker = new Employee(newid, newname, newselect);
                break;
            case 2:
                worker = new Manager(newid, newname, newselect);
                break;
            case 3:
                worker = new Boss(newid, newname, newselect);
            default:
                break;
            }
            this->m_emparry[ret] = worker;
            cout << "�޸ĳɹ�!" << endl;
            this->save();
        }
        else
        {
            cout << "���޴���,�޸�ʧ��" << endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::find_emp()
{
    if (this->file_empty)
    {
        cout << "�ļ������ڻ��¼Ϊ��" << endl;
    }
    else
    {
        cout << "��ѡ����ҷ�ʽ" << endl;
        cout << "1.��ְ����Ų���" << endl;
        cout << "2.��ְ����������" << endl;
        int select;
        cin >> select;
        if (select == 1)
        {
            cout << "������ְ���ı��" << endl;
            int id;
            cin >> id;
            int ret = this->is_exit(id);
            if (ret != -1)
            {
                cout << "�ҵ��ˣ�ְ������Ϣ����" << endl;
                this->m_emparry[ret]->show_inf();
            }
            else
            {
                cout << "����ʧ��" << endl;
            }
        }
        else if (select == 2)
        {
            cout << "��������ҵ�ְ������" << endl;
            string name;
            cin >> name;
            bool flage = false;
            for (int i = 0; i < this->m_empnum; i++)
            {
                if (this->m_emparry[i]->m_Name == name)
                {
                    cout << "���ҳɹ�����ְ����Ϣ����" << endl;
                    this->m_emparry[i]->show_inf();
                    flage = true;
                }
            }
            if (flage != true)
            {
                cout << "����ʧ��" << endl;
            }
        }
        else
        {
            cout << "����ѡ���������������" << endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::sort_emp()
{
    if (this->file_empty)
    {
        cout << "�ļ������ڻ��¼Ϊ��" << endl;
    }
    else
    {
        cout << "��ѡ������ʽ" << endl;
        cout << "1.����" << endl;
        cout << "2.����" << endl;
        int select = 0;
        cin >> select;
        for (int i = 0; i < this->m_empnum; i++)
        {
            int maxormin = i;
            for (int j = i + 1; j < this->m_empnum; j++)
            {
                if (select == 1)
                {
                    if (this->m_emparry[maxormin]->m_Id > this->m_emparry[j]->m_Id)
                    {
                        maxormin = j;
                    }
                }
                else
                {
                    if (this->m_emparry[maxormin]->m_Id < this->m_emparry[j]->m_Id)
                    {
                        maxormin = j;
                    }
                }
            }
            if (i != maxormin)
            {
                Worker* tmp = this->m_emparry[i];
                this->m_emparry[i] = this->m_emparry[maxormin];
                this->m_emparry[maxormin] = tmp;
            }
        }
    }
    cout << "����ɹ�����������" << endl;
    this->save();
    this->show_emp();
}

void WorkerManager::clean_file()
{
    cout << "ȷ����գ�" << endl;
    cout << "1.ȷ��" << endl;
    cout << "2.����" << endl;
    int select = 0;
    cin >> select;

    if (select == 1)
    {
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();

        if (this->m_emparry != NULL)
        {
            for (int i = 0; i < this->m_empnum; i++)
            {
                delete this->m_emparry[i];
                this->m_emparry[i] = NULL;
            }
            delete[]this->m_emparry;
            this->m_emparry = NULL;
        }
        cout << "��ճɹ�" << endl;
    }
    system("pausse");
    system("cls");
}

void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);
    for (int i = 0; i < this->m_empnum; i++)
    {
        ofs << this->m_emparry[i]->m_Id << " "
            << this->m_emparry[i]->m_Name << " "
            << this->m_emparry[i]->DepId << endl;
    }
    ofs.close();
}

int WorkerManager::get_num()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int num = 0;

    int id;
    string name;
    int depid;
    while (ifs >> id && ifs >> name && ifs >> depid)
    {
        num++;
    }
    ifs.close();
    return num;
}

void WorkerManager::init_emp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int depid;
    int index = 0;

    while (ifs >> id && ifs >> name && ifs >> depid)
    {
        Worker* worker = NULL;
        if (id == 1)
        {
            worker = new Employee(id, name, depid);
        }
        else if (id == 2)
        {
            worker = new Manager(id, name, depid);
        }
        else
        {
            worker = new Boss(id, name, depid);
        }
        this->m_emparry[index] = worker;
        index++;
    }
    ifs.close();
}

WorkerManager::~WorkerManager()
{
    if (this->m_emparry != NULL)
    {
        for (int i = 0; i < this->m_empnum; i++)
        {
            if (this->m_emparry[i] != NULL)
            {
                delete this->m_emparry[i];
            }
        }
        delete[]this->m_emparry;
        this->m_emparry = NULL;
    }
}