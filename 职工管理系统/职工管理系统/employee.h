#pragma once
using namespace std;
#include <iostream>
#include"worker.h"
//��ͨԱ����
class Employee:public Worker
{
public:
	//���캯��
	Employee(int id, string name, int dId);

	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡ��λ��Ϣ
	virtual string getDeptName();

};
