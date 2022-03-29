#include "workerManager.h"


//初始化
WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//文件不存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		m_EmpNum = 0;
		m_EmpArray = NULL;
		m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件存在为空 
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		m_EmpNum = 0;
		m_EmpArray = NULL;
		m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件存在并记录数据
	int num = get_EmpNum();
	cout << "职工的人数为:  " << num << endl;
	m_EmpNum = num;


	m_EmpArray = new Worker * [m_EmpNum];
	//文件数据存入数组
	init_Emp();
}
//打印菜单
void WorkerManager::Show_menu()
{
	cout << "******************************************" << endl;
	cout << "******************************************" << endl;
	cout << "*******    欢迎使用职工管理系统!    ******" << endl;
	cout << "***********  0.退出管理系统  *************" << endl;
	cout << "***********  1.增加职工信息  *************" << endl;
	cout << "***********  2.显示职工信息  *************" << endl;
	cout << "***********  3.删除职工信息  *************" << endl;
	cout << "***********  4.修改职工信息  *************" << endl;
	cout << "***********  5.查找职工信息  *************" << endl;
	cout << "***********  6.按照编号排序  *************" << endl;
	cout << "***********  7.清空所有文档  *************" << endl;
	cout << "******************************************" << endl;
	cout << endl;
}
//退出函数
void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);//退出
}
//添加职工
void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工的数量" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//添加
		//计算添加新空间的大小
		int newSize = m_EmpNum + addNum;

		//开辟新空间
		Worker** newSpace = new Worker * [newSize];

		//将原有数据拷贝进入新空间
		if (m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				newSpace[i] = m_EmpArray[i];
			}
		}
		//添加新职工

		int id;
		string name;
		int dId;
		int dSelect;
		for (int i = 0; i < addNum; i++)
		{
			cout << "请输入第" << i + 1 << "个员工的id" << endl;;
			cin >> id;
			bool flag = false;
			for (int j = 0; j < m_EmpNum + i; j++)
			{
				if (newSpace[j]->m_id == id)
				{
					flag = true;
				}
				if (flag == true)
				{
					cout << "该id已经存在，请输入其他编号" << endl;
					cin >> id;
					j = 0;
					flag = false;
				}
			}
			
			cout << "请输入第" << i + 1 << "个员工的名字" << endl;
			cin >> name;
			cout << "请选择职工的岗位" << endl;
			cout << "1、 普通职工" << endl;
			cout << "2、 经理" << endl;
			cout << "3、 总裁" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
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
			default:
				break;
			}
			newSpace[m_EmpNum + i] = worker;
		}
		//释放原有空间
		delete[] m_EmpArray;
		//更改职工数量
		m_EmpNum = newSize;
		//更改指向
		m_EmpArray = newSpace;
		//更新职工不为空
		m_FileIsEmpty = false;
		cout << "添加成功 请按任意键继续" << endl;
		this->save();
	}
	else
	{
		cout << "输入数据有误" << endl;
	}
	system("pause");
	system("cls");
}
//存粹数据
void WorkerManager::save()
{
	fstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < m_EmpNum; i++)
	{
		ofs << m_EmpArray[i]->m_id << " "
			<< m_EmpArray[i]->m_name << " "
			<< m_EmpArray[i]->m_dId << endl;
	}
}
//统计成员中的函数 
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int num = 0;
	int id;
	string name;
	int dId;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//统计人数
		num++;
	}
	return num;
}
//初始化员工
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;

		if (dId == 1)//普通员工
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)//经理
		{
			worker = new Manager(id, name, dId);
		}
		else if (dId == 3)//总裁
		{
			worker = new Boss(id, name, dId);
		}
		m_EmpArray[index] = worker;
		index++;
	}

	//关闭文件
	ifs.close();
}
//显示员工
void WorkerManager::show_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
//判断职工是否存在
int WorkerManager::IsExit(int id)
{
	int index = -1;

	for (int i = 0; i < m_EmpNum; i++)
	{
		if (m_EmpArray[i]->m_id == id)
		{
			index = i;
		}
	}
	return index;
}
//删除成员 
void WorkerManager::del_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "文件不存在" << endl;
	}
	else
	{
		cout << "输入你想要删除的员工" << endl;
		int id = 0;
		cin >> id;
		int ret = IsExit(id);
		if (ret == -1)
		{
			cout << "删除失败，该员工不存在" << endl;
		}
		else
		{
			//删除员工
			for (int i = ret; i < m_EmpNum; i++)
			{
				m_EmpArray[i] = m_EmpArray[i + 1];
			}
			cout << "删除成功" << endl;
			m_EmpNum--;
			save();
		}
	}

	system("pause");
	system("cls");
}
//修改职员
void WorkerManager::Mod_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "文件不存在" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号" << endl;
		int id;
		cin >> id;

		int ret = IsExit(id);
		if (ret != -1)
		{
			//查找编号的职工

			delete m_EmpArray[ret];
			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到: " << id << "请输入新的职工号: " << endl;
			cin >> newId;

			cout << "请输入新的姓名： " << endl;
			cin >> newName;

			cout << "请选择职工的岗位" << endl;
			cout << "1、 普通职工" << endl;
			cout << "2、 经理" << endl;
			cout << "3、 总裁" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, 1);
				break;
			case 2:
				worker = new Manager(newId, newName, 2);
				break;
			case 3:
				worker = new Boss(newId, newName, 3);
				break;
			default:
				break;
			}
			//更改数据到数组中
			m_EmpArray[ret] = worker;

			cout << "修改成功" << m_EmpArray[ret]->getDeptName()<< endl;

			//保存至文件中
			save();
		}
		else
		{
			cout << "修改失败，查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}
//查找职员
void WorkerManager::Find_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "文件不存在或者为空" << endl;
	}
	else
	{
		cout << "请输入查找方式" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按职工名字查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "输入需要查找的员工序号" << endl;
			int goal_Id;
			cin >> goal_Id;
			int ret = IsExit(goal_Id);
			if (ret != -1)
			{
				cout << "查找的员工信息如下" << endl;
				m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "该员工不存在" << endl;
			}
		}
		else if (select == 2)
		{
			cout << "输入需要查找的员工名字" << endl;
			string goal_Name;
			cin >> goal_Name;
			bool flag = false;
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_name == goal_Name)
				{
					m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "该员工不存在" << endl;
			}
		}
		else 
		{
			cout << "选择错误" << endl;
		}
	}
	system("pause");
	system("cls");
}
//职员排序
void WorkerManager::Sort_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "文件不存在或为空" << endl;
	}
	else
	{
		cout << "选择你要排序的方式" << endl;
		cout << "1、按编号升序 " << endl;
		cout << "2、按编号降序 " << endl;
		int select = 0;
		cin >> select;

		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i+1; j < m_EmpNum; j++)
			{
				if (select == 1)
				{
					if (m_EmpArray[j]->m_id < m_EmpArray[minOrMax]->m_id)
					{
						minOrMax = j;
					}
				}
				else if (select == 2)
				{
					if (m_EmpArray[j]->m_id > m_EmpArray[minOrMax]->m_id)
					{
						minOrMax = j;
					}
				}
				if (minOrMax != i)
				{
					Worker* temp = m_EmpArray[minOrMax];
					m_EmpArray[minOrMax] = m_EmpArray[i];
					m_EmpArray[i] = temp;
				}
			}
		}
		cout << "排序成功 " << endl;
		system("pause");
		system("cls");
	}
}
//清空职工表
void WorkerManager::Empty_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "文件不存在或文件为空" << endl;
	}
	else
	{
		//清空文件
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);
		//释放堆区数据
		if (m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i] != NULL)
				{
					delete m_EmpArray[i];
				}
			}
			//初始化职工管理系统相关属性
			delete[] m_EmpArray;
			m_EmpNum = 0;
			m_FileIsEmpty = true;
			cout << "职工列表已清除" << endl;
		}
	}
	system("pause");
	system("cls");
}
//析构函数
WorkerManager::~WorkerManager()
{

}