#include <iostream>
using namespace std;

class A
{};

class B: public A
{};

class Person
{
public:
    virtual A* ByTicket()
    {
        cout << "正常排队----全价格买票" << endl;
        return new A;
    }
};

class Student: public Person
{
public:
    virtual B* ByTicket()
    {
        cout << "正常排队----半价格买票" << endl;
        return new B;
    }
};

void Buy(Person& p)
{
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
