#pragma once // �ж�ͷ�ļ��������Ƿ��ظ�
#include<iostream>
#include<fstream>
using namespace std;
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#define FILENAME "empfile.txt"
class WorkerManager
{
public:
	//���캯��
	WorkerManager();
	//չʾ�˵�
	void Show_menu();
	//�˳�����
	void ExitSystem();
	//��¼ְ������
	int m_EmpNum;
	//ְ������ָ��
	Worker** m_EmpArray;
	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;
	//���ְ��
	void Add_Emp();
	//�洢����
	void save();
	//ͳ���ļ��е����� 
	int get_EmpNum();
	//��ʼ��Ա��
	void init_Emp();
	//��ʾԱ��
	void show_Emp();
	//�ж�ְ���Ƿ����
	int IsExit(int id);
	//ɾ����Ա 
	void del_Emp();
	//�޸�ְԱ
	void Mod_Emp();
	//����ְԱ
	void Find_Emp();
	//Ա������
	void Sort_Emp();
	//���ְ����
	void Empty_Emp();
	//��������
	~WorkerManager();
};
