#include <iostream>
using namespace std;

class Person
{
public:
    virtual void ByTicket()
    {
        cout << "正常排队----全价格买票" << endl;
    }
};

class Student: public Person
{
public:
    virtual void ByTicket()
    {
        cout << "正常排队----半价格买票" << endl;
    }
};

// 1、继承类中，虚函数的重写。
//    重写的条件：
//          a. 父子类中的函数都必须是虚函数。
//          b. 函数名、参数、返回值都要相同。
// 2、基类指针或者指针去调用这个虚函数。
//    指向谁，调用谁的虚函数
void Buy(Person& p)
{
  	// 不满足多态：跟类型有关，也就是说p是什么类型，就调用这个类型的成员函数。
  	// 满足多态：跟对象有关，也就是说指向的是哪个对象就调用哪个的虚函数。
    p.ByTicket();
}

int main()
{
    Person p;
    Buy(p);

    Student s;
    Buy(s);

    return 0;
}
