#include<iostream>
using namespace std;
#include"workerManager.h"
#include "worker.h"
#include "employee.h"
int main()
{

	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		wm.Show_menu();

		cout << "请输入你的选择； " << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			wm.ExitSystem();
			break;
		case 1://添加职工
			wm.Add_Emp();
			break;
		case 2://显示职工
			wm.show_Emp();
			break;
		case 3://删除职工
			wm.del_Emp();
			break;
		case 4://修改职工
			wm.Mod_Emp();
			break;
		case 5://查找职工
			wm.Find_Emp();
			break;
		case 6://职工排序
			wm.Sort_Emp();
			break;
		case 7://清空文档
			wm.Empty_Emp();
			break;
		default:
			system("cls");
			break;

		}
	}
	system("pause");

	return 0;
}
