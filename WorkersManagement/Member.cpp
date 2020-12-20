#include "Member.h"

// 普通员工方法实现
Employee::Employee(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Employee::showInfo()
{
	cout << "职工编号: "   << this->m_Id
		 << "\t职工姓名: " << this->m_Name
	 	 << "\t岗位: " << this->getDeptName()
		 << "\t岗位职责: 完成经理分配的任务"
		 << endl; 
}

string Employee::getDeptName()
{
	return string("员工");
}

Manager::Manager(int id, string name, int dId)
{
	this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

// 显示个人信息
void Manager::showInfo()
{
	cout << "职工编号: "   << this->m_Id
         << "\t职工姓名: " << this->m_Name
         << "\t岗位: " << this->getDeptName()
         << "\t岗位职责: 完成老板分配的任务,给普通员工分配任务"
         << endl;
}

// 获取岗位名称
string Manager::getDeptName()
{
	return string("经理");
}


Boss::Boss(int id, string name, int dId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

// 显示个人信息
void Boss::showInfo()
{
    cout << "职工编号: "   << this->m_Id
         << "\t职工姓名: " << this->m_Name
         << "\t岗位: " << this->getDeptName()
         << "\t岗位职责: 管理员工"
         << endl;
}

// 获取岗位名称
string Boss::getDeptName()
{
    return string("老板");
}
