#include"boss.h"

//构造函数
Boss::Boss(int id, string name, int dId)
{
	m_id = id;
	m_name = name;
	m_dId = dId;
}

//显示个人信息
void Boss::showInfo()
{
	cout << "成员的编号是： " << m_id
		<< "\t职工姓名： " << m_name
		<< "\t岗位：  " << getDeptName()
		<< "岗位职责： 管理整个公司" << endl;
}
//获取岗位信息
string Boss::getDeptName()
{
	return string("总裁");
}
