#include <iostream>
using namespace std;

class MyInteger
{
	friend ostream& operator<<(ostream &cout, MyInteger &myint);
public:
	MyInteger()
	{
		m_A = 0;
	}

	MyInteger& operator++() // 前置递增
	{
		this->m_A += 1;
		return *this;
	}

	MyInteger operator++(int)
	{
		MyInteger temp = *this;
		this->m_A+=1;
		return temp;	
	}

private:
	int m_A;
};

ostream& operator<<(ostream &cout, MyInteger &myint)
{
	cout << myint.m_A;
	return cout;
}

void test01()
{
	MyInteger myint;
	cout << ++(++myint) << endl;
	cout << myint << endl;
}

void test02()
{
	MyInteger myint;
	cout << myint++ << endl;
	cout << myint << endl;
}

int main()
{
	test02();
	return 0;
}
