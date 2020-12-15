#include <iostream>
using namespace std;

class MyInt
{
	friend ostream& operator<<(ostream &cout , MyInt &mi);
public:
	MyInt(int age)
	{
		this->m_A = age;
	}

	MyInt& operator--() // 前置--
	{
		this->m_A -= 1;
		return *this;
	}

	MyInt operator--(int) // 后置--
	{
		MyInt temp = *this;
		this->m_A -= 1;
		return temp;
	}
private:
	int m_A;
};

ostream& operator<<(ostream &cout , MyInt &mi)
{
	cout << mi.m_A;
	return cout;	
}

void test01()
{
	MyInt mi(19);
	cout << --(--mi) << endl;
	--mi;
	cout << mi << endl;
	cout << "=======" << endl;

	// cout << "mi--:" << mi-- << endl;
	// cout << "mi:"  << mi << endl;
}

int main()
{
	test01();
	return 0;
}
