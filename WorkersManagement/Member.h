#pragma once
#include <iostream>
using namespace std;
#include <string>

class Worker
{
public:
	// 显示个人信息
	virtual void showInfo() = 0;
	// 获取岗位名称
	virtual string getDeptName() = 0;	
	// 职工编号
	int m_Id;
	// 职工姓名
	string m_Name;
	// 部门编号
	int m_DeptId;
};

// 普通员工
class Employee:public Worker
{
public:
	// 构造函数
	Employee(int id, string name, int dId);

	// 显示个人信息
	virtual void showInfo();

	// 获取岗位名称
	virtual string getDeptName();
};

// 经理

class Manager:public Worker
{
public:
	Manager(int id, string name, int dId);

	// 显示个人信息
    virtual void showInfo();

    // 获取岗位名称
    virtual string getDeptName();
};

class Boss:public Worker
{
public:
	// 构造函数
    Boss(int id, string name, int dId);

    // 显示个人信息
    virtual void showInfo();

    // 获取岗位名称
    virtual string getDeptName();
};
