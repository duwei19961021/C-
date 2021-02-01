#include <iostream>
using namespace std;

int main()
{
	int array[] = {11,5,3,8,0,10};
	for(int i = 0; i < sizeof(array) / sizeof(array[0]);i++)
		cout << array[i] << " ";

	cout << endl;


	for(auto e : array) // 取array中的值拷贝给e,修改e不影响array中的值
		e*=2;
	
	cout << "不使用引用: ";
	for(auto e : array)
		cout << e << " ";

	cout << endl;

	cout << "使用引用: ";
	for(auto& e : array)
		e*=2;
	
	for(auto e : array)
		cout << e << " ";

	return EXIT_SUCCESS;
}
