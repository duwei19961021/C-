#include <iostream>
#include <fstream>
using namespace std;

class Person
{
public:
	

	char m_Name[64];
	int m_Age;
};

void test01()
{
	ofstream ofs("Person.txt",ios::out | ios::binary);	

	Person p = {"杜维",24};
	
	ofs.write((const char *)&p,sizeof(Person));
	ofs.close();
}

void test02()
{
	ifstream ifs;
	ifs.open("Person.txt",ios::in | ios::binary);
	if(!ifs.is_open())
	{
		cout << "open file fialed." << endl;
		return;
	}

	Person p;
	ifs.read((char *)&p,sizeof(Person));
	cout << p.m_Name << endl;
	cout << p.m_Age << endl;
	ifs.close();
}

int main()
{
	test02();
	return 0;
}
