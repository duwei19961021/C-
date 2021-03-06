#include <vector>
#include <iostream>
#include <string>
using std::vector;
using std::string;
/**
 * vector是一个类模板。
 * 模板本身不是类或者函数，可以将模板看做编译器生成类或函数编写的一份说明。
 * 编译器根据模板创建类或函数的过程叫实例化。
 * 使用模板时应当指出编译器把类或函数实例化成何种类型。
 */

void PrintIntVector(vector<int>& i_vec)
{
	std::cout << "[ ";;
	for(size_t i = 0; i < i_vec.size(); i++)
	{
		std::cout << i_vec[i] << " ";
	}
	std::cout << "]" << std::endl;
}

int main()
{
#if 0
	/*
	// vector中不能保存引用，因为引用不是对象
	std::vector<int&> v;	
	*/

	// 定义和初始化
	std::vector<int> i_vec1; // 初始为空
	std::vector<int> i_vec2(i_vec1); // 拷贝i_vec1的元素给i_vec2
	std::vector<int> i_vec3 = i_vec2;
	std::vector<int> i_vec4(10,9); // 10个9	
	std::vector<int> i_vec5{1,2,3}; // c++11: 列表初始化
	std::vector<int> i_vec6 = {1,2,3}; // c++11: 列表初始化
	/**
	 * 使用拷贝初始化(使用=)时只能提供一个初始值。
	 * 如果提供的是一个类内初始值则只能使用拷贝初始化或者花括号的形式初始化。
	 * 如果提供的是初始元素值的列表则只能使用花括号形式而不能使用圆括号。
	 */
	
	//值初始化: 通常情况下，可以只提供vector对象容纳的元素数量，此时库会根据元素类型初始化值。
	// 有两种限制：
	// 			对于某些类必须明确的提供初始值,如果元素类型不支持默认初始化则必须提供元素的初始值。
	// 			如果只提供了元素的数量而没有设定初始值，只能使用直接初始化。(错误写法:vector<int> v = 10;)
	std::vector<int> i_vec7(10); // 10个0
	for(auto e:i_vec7)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	std::vector<std::string> s_vec8(5); // 5个空串
	for(auto e:s_vec8)
	{
		std::cout << "\"" << e << "\" ";
	}

	// 圆括号可以说是提供的值是用来构造vector对象的
	// 花括号可以认为是列表初始化vector对象
	std::vector<int> i_vec8(10); // 10个0
	std::vector<int> i_vec9{10}; // 1个10
	std::vector<int> i_vec10(10,1); // 10个1
	std::vector<int> i_vec11{10,1}; // 两个元素: 10 ,1

	std::vector<std::string> s_vec12{"hello","world"}; // 列表初始化
	for(auto e:s_vec12)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	// std::vector<std::string> s_vec13("duwei"); 错误写法
	
	// 如果想使用列表初始化,那么花括号里的值必须和元素类型相同,很明显无法使用int初始化string对象
	// 确认无法指向列表初始化之后,编译器会尝试使用默认值初始化vector对象。 
	std::vector<std::string> s_vec14{7}; // 7个空串
	for(auto e:s_vec14)
	{
		std::cout << "\"" << e << "\" ";
	}
	std::cout << std::endl;

	std::vector<std::string> s_vec15{10,"yes"}; // 10个"yes"串
	for(auto e:s_vec15)
	{
		std::cout << "\"" << e << "\" ";
	}

	vector<vector<int>> ivec;
	// vector<string> s_vec16 = ivec; 错误
	vector<string> s_vec17(10,"null");	
	for(auto e : s_vec17)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	vector<int> v1; // 空
	vector<int> v2(10); // 10个0
	vector<int> v3(10,42); // 10个42
	vector<int> v4{10}; // 一个元素: 10
	vector<int> v5{10,42}; // 两个元素: 10、42
	vector<string> v6{10}; // 10个空字符串
	vector<string> v7{10,"hi"}; // 10个字符串 "hi"

	// 向vector中添加元素
	// 如果循环体内含有向vector对象添加元素的语句则不能使用范围for
	vector<int> v8;
	v8.push_back(0); // 从尾部插入
	for(int i = 1; i < 10; i++)
	{
		v8.push_back(i);
	}
	PrintIntVector(v8);	

	int num;
	vector<int> v9;
	while(std::cin >> num)	
	{
		v9.push_back(num);
	}
	PrintIntVector(v9);

	vector<int> v10;
	v10.push_back(1);
	v10.push_back(2);
	v10.push_back(3);
	v10.push_back(4);
	std::cout << v10.empty() << std::endl; // 判断是否为空
	std::cout << v10.size() << std::endl; // 获取元素个数	
	std::cout << v10[2] << std::endl; // 返回第2个元素的引用
	v10 = {8,9}; // 列表中的元素将替换v10原有的元素
	PrintIntVector(v10);
	vector<int> v11{8,9};
	if(v11 == v10) // 仅当元素个数相同且对应位置上的元素值相同时才相等,还支持!= > < >= <=
	{
		std::cout << "v11 == v10" << std::endl;
	}

	vector<int> v12{1,2,3,4,5,6,7,8,9,10,11,12,13};
	for(auto &e : v12)
	{
		std::cout << e << std::endl;
	}
	vector<int>::size_type size = v12.size();
	std::cout << "size = " << size << std::endl;

	vector<int> v13;
	v13[0] = 1; // 不能通过下标的方式添加元素
	PrintIntVector(v13);

	// 迭代器
	vector<int> v14(10,9);
	// auto b = v14.begin(); // b指向容器的第一个成员
	vector<int>::iterator b = v14.begin();
	auto e = v14.end();	 // e指向尾元素的下一个位置,end()返回的迭代器通常被称为尾后迭代器。因为end迭代器并不指向实际某个元素,所以不能对其进行自增或者解引用
//	e++;
//	std::cout << "*e = "<< *e << std::endl;
//	e--;
//	e--;
//	std::cout << "*e = "<< *e << std::endl;
	std::cout << *b << std::endl;
	++b; // 使b指向容器的下一个元素
	if(b == e)
	{
		std::cout << "b == e" << std::endl;
	}
	else
	{
		std::cout << "b != e" << std::endl;
	}

	// 迭代器类型
	vector<int>::iterator it = v14.begin(); // 能通过迭代器修改元素的值	
	vector<int>::const_iterator c_it = v14.begin(); // 不能通过迭代器修改元素的值
	// begin和end返回的具体类型有对象是否是常量决定,如果对象是常量则返回const_iterator,不是常量则返回iterator
	auto it3 = v14.cbegin(); // c++11: 返回const_iterator类型迭代器

	// 某些对vector的对象操作可能会使迭代器失效,谨记: 但凡使用了迭代器的循环体,都不要向迭代器所属的容器添加元素。
	vector<int> v15{1,2,3,4};
	for(auto it = v15.begin(); it!=v15.end(); it++)
	{
		if(*it % 2 == 0)
		{
			v15.push_back(*it + 1);
		}
	}
	PrintIntVector(v15); // [ 1 2 3 4 3 5 1 1 1 1 1 5 1 1 1 3 5 1 1 1 3 5 ],和预期结果不一样哦
#endif

	// 迭代器运算
	// 迭代器的递增运算使迭代器每次移动一个元素,所有标准库容器都支持递增运算的迭代器。
	// string 和 vector的迭代器提供了更多额外的运算符,一方面支持一次移动多个元素,另一方面也支持迭代器进行关系运算。	
	// 例如: iter+n、iter+=n、iter-n、iter-=n、iter1-iter2、>、<、>=、<=
	
	// 不允许使用一个数组为另一个内置类型的数组赋初值,也不允许使用vector对象初始化数组,但是允许使用数组初始化vector对象(需要指明要拷贝区域的首元素地址和尾后地址)
	int arr[3] = {1,2,3};
	vector<int> v16(std::begin(arr), std::end(arr));
	PrintIntVector(v16);
	vector<int> v17(arr,arr+2);
	PrintIntVector(v17);
}
