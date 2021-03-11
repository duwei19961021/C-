#include <iostream>
#include <cstddef>
#include <string>
using namespace std;

/*
 * Foo* p = new Foo(x);
 * Foo* p = (Foo *)operator new(sizeof(Foo)); => ::operator new(size_t); => malloc(size_t);
 * new (p)Foo(x); // 定点初始化
 *
 * delete p;
 * p->~Foo(); operator delete(p); => ::operator delete(void*); => free(void*);
 *
 * 调用一次malloc分配内存,分配出来的内存首位会有两个cookie标记这块内存的长度,32位下两个cookie就是8字节,如果分配100w块内存,那么cookie就会占用800w个字节,造成很大的浪费。
 */

class Foo
{
public:
	int _id;
	int _data;
	string _str;

public:
	Foo():_id(0)
	{
		cout << "default.ctor.this=" << this << " id=" << _id << endl;
	}

	Foo(int i):_id(i)
	{
		cout << "ctor.this=" << this << " id=" << _id << endl;	
	}

	~Foo()
	{
		cout << "dtor.this=" << this << " id=" << _id << endl;
	}

static void* operator new(size_t size);
static void operator delete(void* phead ,size_t size);
static void* operator new[](size_t size);
static void operator delete[](void* phead ,size_t size);
};

void* Foo::operator new(size_t size)
{
	Foo* p = (Foo *)malloc(size);
	cout << "operator new" << endl;
	return p;
}

void Foo::operator delete(void* phead, size_t size)
{
	cout << "operator delete" << endl;
	free(phead);
}

void* Foo::operator new[](size_t size)
{
	Foo* p = (Foo *)malloc(size);
	cout << "operator new[]" << endl;
	return p;
}

void Foo::operator delete[](void* phead, size_t size)
{
	cout << "operator delete[]" << endl;
	free(phead);
}

int main()
{
	Foo* p = new Foo(10);
	delete p;

//	Foo* p2 = new Foo[2];
//	delete[] p2;
}
