#pragma once
#include<iostream>
using namespace std;
#include <string>

//ְ��������
class Worker
{
public:
	//��ʾ������Ϣ
	virtual void showInfo() = 0;

	//��ȡ��λ����
	virtual string getDeptName() = 0;

	//��Ա����
	int m_id;
	string m_name;
	int m_dId;
};

