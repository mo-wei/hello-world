#pragma once
using namespace std;
#include <iostream>
#include"worker.h"
//普通员工类
class Employee:public Worker
{
public:
	//构造函数
	Employee(int id, string name, int dId);

	//显示个人信息
	virtual void showInfo();

	//获取岗位信息
	virtual string getDeptName();

};
