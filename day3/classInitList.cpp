#include <iostream>
using namespace std;

class Person
{
	public:
		Person() :m_A(10),m_B(20),m_C(30) // 初始化列表初始化属性
			   {
			   
			   }
	int m_A;
	int m_B;
	int m_C;
};

int main()
{
	Person p;
	cout << "p.m_A = " << p.m_A << endl;
	cout << "p.m_B = " << p.m_B << endl;
	cout << "p.m_C = " << p.m_C << endl;
	return 0;
}
