#pragma once // 判断头文件的引用是否重复
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
	//构造函数
	WorkerManager();
	//展示菜单
	void Show_menu();
	//退出函数
	void ExitSystem();
	//记录职工人数
	int m_EmpNum;
	//职工数组指针
	Worker** m_EmpArray;
	//判断文件是否为空
	bool m_FileIsEmpty;
	//添加职工
	void Add_Emp();
	//存储数据
	void save();
	//统计文件中的人数 
	int get_EmpNum();
	//初始化员工
	void init_Emp();
	//显示员工
	void show_Emp();
	//判断职工是否存在
	int IsExit(int id);
	//删除成员 
	void del_Emp();
	//修改职员
	void Mod_Emp();
	//查找职员
	void Find_Emp();
	//员工排序
	void Sort_Emp();
	//清空职工表
	void Empty_Emp();
	//析构函数
	~WorkerManager();
};
