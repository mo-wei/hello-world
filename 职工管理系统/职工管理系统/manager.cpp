#include "manager.h"


//构造函数
Manager::Manager(int id, string name, int dId)
{
	m_id = id;
	m_name = name;
	m_dId = dId;
}

//显示个人信息
void Manager::showInfo()
{
	cout << "成员的编号是： " << m_id
		<< "\t职工姓名： " << m_name
		<< "\t岗位：  " << getDeptName()
		<< "岗位职责： 传达老板的命令" << endl;
}

//获取岗位信息
string Manager::getDeptName()
{
	return string("经理");
}
