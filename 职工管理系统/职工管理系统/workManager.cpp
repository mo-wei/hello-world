#include "workerManager.h"


//��ʼ��
WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//�ļ�������
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		m_EmpNum = 0;
		m_EmpArray = NULL;
		m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ�����Ϊ�� 
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		m_EmpNum = 0;
		m_EmpArray = NULL;
		m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ����ڲ���¼����
	int num = get_EmpNum();
	cout << "ְ��������Ϊ:  " << num << endl;
	m_EmpNum = num;


	m_EmpArray = new Worker * [m_EmpNum];
	//�ļ����ݴ�������
	init_Emp();
}
//��ӡ�˵�
void WorkerManager::Show_menu()
{
	cout << "******************************************" << endl;
	cout << "******************************************" << endl;
	cout << "*******    ��ӭʹ��ְ������ϵͳ!    ******" << endl;
	cout << "***********  0.�˳�����ϵͳ  *************" << endl;
	cout << "***********  1.����ְ����Ϣ  *************" << endl;
	cout << "***********  2.��ʾְ����Ϣ  *************" << endl;
	cout << "***********  3.ɾ��ְ����Ϣ  *************" << endl;
	cout << "***********  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "***********  5.����ְ����Ϣ  *************" << endl;
	cout << "***********  6.���ձ������  *************" << endl;
	cout << "***********  7.��������ĵ�  *************" << endl;
	cout << "******************************************" << endl;
	cout << endl;
}
//�˳�����
void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);//�˳�
}
//���ְ��
void WorkerManager::Add_Emp()
{
	cout << "���������ְ��������" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//���
		//��������¿ռ�Ĵ�С
		int newSize = m_EmpNum + addNum;

		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		//��ԭ�����ݿ��������¿ռ�
		if (m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				newSpace[i] = m_EmpArray[i];
			}
		}
		//�����ְ��

		int id;
		string name;
		int dId;
		int dSelect;
		for (int i = 0; i < addNum; i++)
		{
			cout << "�������" << i + 1 << "��Ա����id" << endl;;
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
					cout << "��id�Ѿ����ڣ��������������" << endl;
					cin >> id;
					j = 0;
					flag = false;
				}
			}
			
			cout << "�������" << i + 1 << "��Ա��������" << endl;
			cin >> name;
			cout << "��ѡ��ְ���ĸ�λ" << endl;
			cout << "1�� ��ְͨ��" << endl;
			cout << "2�� ����" << endl;
			cout << "3�� �ܲ�" << endl;
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
		//�ͷ�ԭ�пռ�
		delete[] m_EmpArray;
		//����ְ������
		m_EmpNum = newSize;
		//����ָ��
		m_EmpArray = newSpace;
		//����ְ����Ϊ��
		m_FileIsEmpty = false;
		cout << "��ӳɹ� �밴���������" << endl;
		this->save();
	}
	else
	{
		cout << "������������" << endl;
	}
	system("pause");
	system("cls");
}
//�������
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
//ͳ�Ƴ�Ա�еĺ��� 
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
		//ͳ������
		num++;
	}
	return num;
}
//��ʼ��Ա��
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

		if (dId == 1)//��ͨԱ��
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)//����
		{
			worker = new Manager(id, name, dId);
		}
		else if (dId == 3)//�ܲ�
		{
			worker = new Boss(id, name, dId);
		}
		m_EmpArray[index] = worker;
		index++;
	}

	//�ر��ļ�
	ifs.close();
}
//��ʾԱ��
void WorkerManager::show_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
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
//�ж�ְ���Ƿ����
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
//ɾ����Ա 
void WorkerManager::del_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "�ļ�������" << endl;
	}
	else
	{
		cout << "��������Ҫɾ����Ա��" << endl;
		int id = 0;
		cin >> id;
		int ret = IsExit(id);
		if (ret == -1)
		{
			cout << "ɾ��ʧ�ܣ���Ա��������" << endl;
		}
		else
		{
			//ɾ��Ա��
			for (int i = ret; i < m_EmpNum; i++)
			{
				m_EmpArray[i] = m_EmpArray[i + 1];
			}
			cout << "ɾ���ɹ�" << endl;
			m_EmpNum--;
			save();
		}
	}

	system("pause");
	system("cls");
}
//�޸�ְԱ
void WorkerManager::Mod_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "�ļ�������" << endl;
	}
	else
	{
		cout << "�������޸�ְ���ı��" << endl;
		int id;
		cin >> id;

		int ret = IsExit(id);
		if (ret != -1)
		{
			//���ұ�ŵ�ְ��

			delete m_EmpArray[ret];
			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "�鵽: " << id << "�������µ�ְ����: " << endl;
			cin >> newId;

			cout << "�������µ������� " << endl;
			cin >> newName;

			cout << "��ѡ��ְ���ĸ�λ" << endl;
			cout << "1�� ��ְͨ��" << endl;
			cout << "2�� ����" << endl;
			cout << "3�� �ܲ�" << endl;
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
			//�������ݵ�������
			m_EmpArray[ret] = worker;

			cout << "�޸ĳɹ�" << m_EmpArray[ret]->getDeptName()<< endl;

			//�������ļ���
			save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}
	}
	system("pause");
	system("cls");
}
//����ְԱ
void WorkerManager::Find_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҷ�ʽ" << endl;
		cout << "1����ְ����Ų���" << endl;
		cout << "2����ְ�����ֲ���" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			cout << "������Ҫ���ҵ�Ա�����" << endl;
			int goal_Id;
			cin >> goal_Id;
			int ret = IsExit(goal_Id);
			if (ret != -1)
			{
				cout << "���ҵ�Ա����Ϣ����" << endl;
				m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "��Ա��������" << endl;
			}
		}
		else if (select == 2)
		{
			cout << "������Ҫ���ҵ�Ա������" << endl;
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
				cout << "��Ա��������" << endl;
			}
		}
		else 
		{
			cout << "ѡ�����" << endl;
		}
	}
	system("pause");
	system("cls");
}
//ְԱ����
void WorkerManager::Sort_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�Ϊ��" << endl;
	}
	else
	{
		cout << "ѡ����Ҫ����ķ�ʽ" << endl;
		cout << "1����������� " << endl;
		cout << "2������Ž��� " << endl;
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
		cout << "����ɹ� " << endl;
		system("pause");
		system("cls");
	}
}
//���ְ����
void WorkerManager::Empty_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��ļ�Ϊ��" << endl;
	}
	else
	{
		//����ļ�
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);
		//�ͷŶ�������
		if (m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (m_EmpArray[i] != NULL)
				{
					delete m_EmpArray[i];
				}
			}
			//��ʼ��ְ������ϵͳ�������
			delete[] m_EmpArray;
			m_EmpNum = 0;
			m_FileIsEmpty = true;
			cout << "ְ���б������" << endl;
		}
	}
	system("pause");
	system("cls");
}
//��������
WorkerManager::~WorkerManager()
{

}