#include"boss.h"

//���캯��
Boss::Boss(int id, string name, int dId)
{
	m_id = id;
	m_name = name;
	m_dId = dId;
}

//��ʾ������Ϣ
void Boss::showInfo()
{
	cout << "��Ա�ı���ǣ� " << m_id
		<< "\tְ�������� " << m_name
		<< "\t��λ��  " << getDeptName()
		<< "��λְ�� ����������˾" << endl;
}
//��ȡ��λ��Ϣ
string Boss::getDeptName()
{
	return string("�ܲ�");
}
