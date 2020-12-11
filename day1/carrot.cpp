#include <iostream>

int main()
{
	using namespace std;
	int carrots;
	carrots = 25;
	cout << "I have ";
	cout << carrots;
	cout << " carrots.";
	cout << endl;
	carrots = carrots - 1;
	cout << "Crunch, crunch. Now I have " << carrots << " carrots." << endl;

	int num1;
	int num2;
	int num3;
	int num4;
	int num5;
	num1 = num2 = num3 = num4 = num5 = 10; // 从右向左
	cout << "num1 = " << num1 << ",num2 = " <<num2 << ",num3 = "<<num3 << ",num4 = "<< num4 <<",num5 = " <<num5 << endl;
	return 0;
}
