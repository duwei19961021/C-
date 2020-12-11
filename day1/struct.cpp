#include <string>
#include <cstring>
#include <iostream>
struct Stu
{
	char name[20];
	int age;
};

int main()
{
	struct Stu s1;
	s1.age = 24;
	strcpy(s1.name,"duwei");
	std::cout << s1.name << "," << s1.age << " years old." << std::endl;
	return 0;
}
