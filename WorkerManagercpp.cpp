#include "WorkerManager.h"

WorkerManager::WorkerManager()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    //1.文件不存在
    if (!ifs.is_open())
    {
        //cout << "文件打不开" << endl;
        this->m_empnum = 0;
        this->m_emparry = NULL;
        this->file_empty = true;
        ifs.close();
        return;
    }
    //2.文件存在但为空
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        //cout << "文件为空" << endl;
        this->m_empnum = 0;
        this->m_emparry = NULL;
        this->file_empty = true;
        ifs.close();
        return;
    }
    //3.文件存在且有数据
    int num = this->get_num();
   // cout << "文件存在数据且职工人数为: " << num << endl;
    this->m_empnum = num;

    //开辟空间
    this->m_emparry = new Worker * [this->m_empnum];
    //初始化
    this->init_emp();
}

void WorkerManager::show_menu()
{
    cout << "----------------------------------------" << endl;
    cout << "--------  欢迎使用职工管理系统  --------" << endl;
    cout << "-----------  0.退出管理系统  -----------" << endl;
    cout << "-----------  1.增加职工信息  -----------" << endl;
    cout << "-----------  2.显示职工信息  -----------" << endl;
    cout << "-----------  3.删除离职职工  -----------" << endl;
    cout << "-----------  4.修改职工信息  -----------" << endl;
    cout << "-----------  5.查找职工信息  -----------" << endl;
    cout << "-----------  6.按照编号排序  -----------" << endl;
    cout << "-----------  7.清空所有文档  -----------" << endl;
    cout << "----------------------------------------" << endl;
    cout << endl;
}

void WorkerManager::exit_system()
{
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);
}

void WorkerManager::add_emp()
{
    cout << "请输入添加职工数量" << endl;
    int addnum = 0;
    cin >> addnum;
    if (addnum > 0)
    {
        //添加计算新空间的大小
        int newsize = this->m_empnum + addnum;
        Worker** newspace = new Worker * [newsize];

        //判断原先数组中否有数据
        if (this->m_emparry != NULL)
        {
            for (int i = 0; i < this->m_empnum; i++)
            {
                newspace[i] = this->m_emparry[i];
            }
        }
        for (int i = 0; i < addnum; i++)
        {
            int id;      // 职工编号
            string name; // 职工姓名
            int dselect; // 职工部门
            cout << "请输入第" << i + 1 << "个职工编号" << endl;
            cin >> id;
            cout << "请输入第" << i + 1 << "个职工姓名" << endl;
            cin >> name;
            cout << "请输入第" << i + 1 << "个职工部门" << endl;
            cout << "1.普通职工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;
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
            //将创建的职工保存到数组中
            newspace[this->m_empnum + i] = worker;
        }
        //释放原有的空间
        delete[]this->m_emparry;
        //更新新空间的指向
        this->m_emparry = newspace;
        //更新新的职工人数
        this->m_empnum = newsize;
        //提示添加成功
        //文件不为空标志
        this->file_empty = false;
        cout << "成功添加" << addnum << "名新招职工" << endl;
        //保存文件
        this->save();
    }
    else
    {
        cout << "输入的数据有误" << endl;
    }
}

void WorkerManager::show_emp()
{
    if (this->file_empty)
    {
        cout << "文件不存在记录为空" << endl;
    }
    else
    {
        for (int i = 0; i < this->m_empnum; i++)
        {
            //利用多态接口
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
        cout << "文件不存在或记录为空" << endl;
    }
    else
    {
        cout << "请输入要删除的职工编号" << endl;
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
            cout << "删除成功" << endl;
        }
        else
        {
            cout << "找不到要删除的职工编号" << endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::mod_emp()
{
    if (this->file_empty)
    {
        cout << "文件不存在或记录为空" << endl;
    }
    else
    {
        cout << "请输入要修改的职工编号" << endl;
        int id;
        cin >> id;
        int ret = this->is_exit(id);
        if (ret != -1)
        {
            delete this->m_emparry[ret];
            int newid;
            string newname;
            int newselect;

            cout << "查到" << id << "号员工,请输入新的职工号" << endl;
            cin >> newid;
            cout << "查到" << id << "号员工,请输入新的姓名" << endl;
            cin >> newname;
            cout << "查到" << id << "号员工,请输入岗位" << endl;
            cout << "1.普通职工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;
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
            cout << "修改成功!" << endl;
            this->save();
        }
        else
        {
            cout << "查无此人,修改失败" << endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::find_emp()
{
    if (this->file_empty)
    {
        cout << "文件不存在或记录为空" << endl;
    }
    else
    {
        cout << "请选择查找方式" << endl;
        cout << "1.按职工编号查找" << endl;
        cout << "2.按职工姓名查找" << endl;
        int select;
        cin >> select;
        if (select == 1)
        {
            cout << "请输入职工的编号" << endl;
            int id;
            cin >> id;
            int ret = this->is_exit(id);
            if (ret != -1)
            {
                cout << "找到了，职工的信息如下" << endl;
                this->m_emparry[ret]->show_inf();
            }
            else
            {
                cout << "查找失败" << endl;
            }
        }
        else if (select == 2)
        {
            cout << "请输入查找的职工姓名" << endl;
            string name;
            cin >> name;
            bool flage = false;
            for (int i = 0; i < this->m_empnum; i++)
            {
                if (this->m_emparry[i]->m_Name == name)
                {
                    cout << "查找成功，该职工信息如下" << endl;
                    this->m_emparry[i]->show_inf();
                    flage = true;
                }
            }
            if (flage != true)
            {
                cout << "查找失败" << endl;
            }
        }
        else
        {
            cout << "输入选项错误，请重新输入" << endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::sort_emp()
{
    if (this->file_empty)
    {
        cout << "文件不存在或记录为空" << endl;
    }
    else
    {
        cout << "请选择排序方式" << endl;
        cout << "1.升序" << endl;
        cout << "2.降序" << endl;
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
    cout << "排序成功，数据如下" << endl;
    this->save();
    this->show_emp();
}

void WorkerManager::clean_file()
{
    cout << "确定清空？" << endl;
    cout << "1.确定" << endl;
    cout << "2.返回" << endl;
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
        cout << "清空成功" << endl;
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