#include <iostream>
#include <string>
using namespace std;

class Calculator
{
public:
	int getResult(string oper)
	{
		if(oper == "+")
		{
			return m_Num1 + m_Num2;
		}
		else if(oper == "-")
		{
			return m_Num1 - m_Num2;
		}
		else if(oper == "*")
		{
			return m_Num1 * m_Num2;
		}
	}
	int m_Num1;
	int m_Num2;
};


void test01()
{
	Calculator c;
	c.m_Num1 = 10;
	c.m_Num2 = 20;
	cout << c.m_Num1 << "+" << c.m_Num2 << "=" << c.getResult("+") << endl; 
	cout << c.m_Num1 << "-" << c.m_Num2 << "=" << c.getResult("-") << endl; 
	cout << c.m_Num1 << "*" << c.m_Num2 << "=" << c.getResult("*") << endl; 
}

// 利用多态实现计算器

// 实现计算器抽象类
class AbstractCalculator
{
public:
	virtual int GetResult()
	{
		return 0;	
	}
	int m_Num1;
	int m_Num2;
};

// 减法计算器类
class AddCalculator:public AbstractCalculator
{
public:
	int GetResult()
	{
		return m_Num1 + m_Num2;
	}
};

class SubCalculator:public AbstractCalculator
{
public:
    int GetResult()
    {
        return m_Num1 - m_Num2;
    }
};

class MulCalculator:public AbstractCalculator
{
public:
    int GetResult()
    {
        return m_Num1 * m_Num2;
    }
};

void test02()
{
	// 多态使用条件
	// 父类指针或者引用指向子类对象
	AbstractCalculator *abc = new AddCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 30;
	cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->GetResult() << endl;
}

int main()
{
	test02();
	return 0;
}
