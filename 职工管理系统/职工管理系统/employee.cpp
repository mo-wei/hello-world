#include"employee.h"
//���캯��
Employee::Employee(int id, string name, int dId)
{
	m_id = id;
	m_name = name;
	m_dId = dId;
}

//��ʾ������Ϣ
void Employee::showInfo()
{
	cout << "��Ա�ı���ǣ� " << m_id
		<< "\tְ�������� " << m_name
		<< "\t��λ��  " << getDeptName()
		<< "��λְ�� ����쵼�´������" << endl;
}

//��ȡ��λ��Ϣ
string Employee::getDeptName()
{
	return string("Ա��");
}