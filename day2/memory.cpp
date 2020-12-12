#include <iostream>
using namespace std;

int g_a = 10;
int g_b = 20;

static int s_g_c = 30;
static int s_g_d = 40;

const int c_g_e = 50;
const int c_g_f = 60;

int main()
{
	static int s_l_g = 70;
	static int s_l_h = 80;

	int l_i = 90;
	int l_j = 100;

	const int c_l_k = 110;
	const int c_l_l = 120;

	cout << "全局变量g_a:" << &g_a << endl;
	cout << "全局变量g_b:" << &g_b << endl;
	cout << "全局静态变量s_g_c:" << &s_g_c << endl;
	cout << "全局静态变量s_g_d:" << &s_g_d << endl;
	cout << "全局常量c_g_e:" << &c_g_e << endl;
	cout << "全局常量c_g_f:" << &c_g_f << endl;
	cout << "局部静态变量s_l_g:" << &s_l_g << endl;
	cout << "局部静态变量s_l_h:" << &s_l_h << endl;
	cout << "局部变量l_i:" << &l_i << endl;
	cout << "局部变量l_j:" << &l_j << endl;
	cout << "局部常量c_l_k:" << &c_l_k << endl;
	cout << "局部常量c_l_l:" << &c_l_l << endl;

	cout << "=============================" << endl;

	cout << "全局变量g_a:" << (long long)&g_a << endl;
	cout << "全局变量g_b:" << (long long)&g_b << endl;
	cout << "全局静态变量s_g_c:" << (long long)&s_g_c << endl;
	cout << "全局静态变量s_g_d:" << (long long)&s_g_d << endl;
	cout << "全局常量c_g_e:" << (long long)&c_g_e << endl;
	cout << "全局常量c_g_f:" << (long long)&c_g_f << endl;
	cout << "局部静态变量s_l_g:" << (long long)&s_l_g << endl;
	cout << "局部静态变量s_l_h:" << (long long)&s_l_h << endl;
	cout << "局部变量l_i:" << (long long)&l_i << endl;
	cout << "局部变量l_j:" << (long long)&l_j << endl;
	cout << "局部常量c_l_k:" << (long long)&c_l_k << endl;
	cout << "局部常量c_l_l:" << (long long)&c_l_l << endl;
	return 0;
}
