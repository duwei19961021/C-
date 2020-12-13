#include <iostream>
using namespace std;

class Person
{
	public:
		//Person() :m_A(10),m_B(20),m_C(30) // 初始化列表初始化属性
		//{
			   
	    //}

		Person(int a, int b, int c):m_A(a),m_B(b),m_C(c)
		{
		
		}
	int m_A;
	int m_B;
	int m_C;
};

int main()
{
	Person p(1,2,3);
	cout << "p.m_A = " << p.m_A << endl;
	cout << "p.m_B = " << p.m_B << endl;
	cout << "p.m_C = " << p.m_C << endl;
	return 0;
}
