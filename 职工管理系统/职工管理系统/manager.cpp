#include "manager.h"


//���캯��
Manager::Manager(int id, string name, int dId)
{
	m_id = id;
	m_name = name;
	m_dId = dId;
}

//��ʾ������Ϣ
void Manager::showInfo()
{
	cout << "��Ա�ı���ǣ� " << m_id
		<< "\tְ�������� " << m_name
		<< "\t��λ��  " << getDeptName()
		<< "��λְ�� �����ϰ������" << endl;
}

//��ȡ��λ��Ϣ
string Manager::getDeptName()
{
	return string("����");
}
