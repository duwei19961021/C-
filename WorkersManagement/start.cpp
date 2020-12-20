#include <iostream>
using namespace std;
#include "workerManager.h"
#include <cstdlib>
#include "Member.h"

int main()
{
	Worker *worker = NULL;
	worker = new Employee(1,"杜维",1);
	worker->showInfo();

	worker = new Manager(2,"张三",2);
	worker->showInfo();

	worker = new Boss(3,"李四",3);
	worker->showInfo();

	WorkerManager wm;
	int select = 0;
	while(true)
	{
		wm.ShowMenu();
		cout << "请输入您的选择: " << endl;
		cin >> select;
		cout << "select = "<< select  << endl;
		switch((int)select)
		{
			case 0:
				wm.exitSystem();
			case 1: //增加职工 
				break;
			case 2: // 显示职工信息
				break;
			case 3: // 删除职工信息
				break;
			case 4: // 修改职工信息
				break;
			case 5: // 查找职工信息 
				break;
			case 6: // 按照编号排序
				break;
			case 7: // 情况
				break;
			default:
				system("clear");
		}
	}
	return 0;	
}
