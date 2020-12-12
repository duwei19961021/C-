#include <iostream>
using namespace std;

/*
 * struct 和 class的区别
 * struct 默认权限是公共 public
 * class  默认权限是私有 private
 * */

class C1
{
	int m_A; // 默认私有权限
};

struct C2
{
	int m_A; //默认权限是公有
};

int main()
{
	C1 c1;
    // c1.m_A;	不可访问
	C2 c2;
	c2.m_A = 10;
	return 0;
}
