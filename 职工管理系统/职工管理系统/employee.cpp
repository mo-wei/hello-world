#include"employee.h"
//构造函数
Employee::Employee(int id, string name, int dId)
{
	m_id = id;
	m_name = name;
	m_dId = dId;
}

//显示个人信息
void Employee::showInfo()
{
	cout << "成员的编号是： " << m_id
		<< "\t职工姓名： " << m_name
		<< "\t岗位：  " << getDeptName()
		<< "岗位职责： 完成领导下达的命令" << endl;
}

//获取岗位信息
string Employee::getDeptName()
{
	return string("员工");
}