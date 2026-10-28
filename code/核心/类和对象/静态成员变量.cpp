#include <iostream>
using namespace std;

/*
静态成员是所有对象共享的
同时静态成员也有跟普通对象一样的访问权限
静态成员只能在类外进行初始化，如果在类内进行初始化会发生同一块内存被重复申请，因为所有对象共享同一块内存
*/

class person
{
private:
    /* data */
public:
    person(/* args */);
    ~person();
    static int m_a; //所有对象都共享同一个静态对象数据
    //类内声明，类外初始化，作用域还在类内
    int b;

    static void func()
    {
        m_a = 1000;
        // b = 100; //静态函数只能访问静态对象 因为函数无法确定访问的是哪个对象的属性（没有this指针）
    }
};

int person::m_a = 10; //静态对象在类外要进行初始化操作

person::person(/* args */)
{
}

person::~person()
{
}

void test()
{
    person p;
    p.func();

    person::func();
}

int main()
{   
    // int person::m_a = 10
    person p;
    cout << p.m_a << endl;

    person p2;
    p2.m_a = 100;
    cout << p.m_a << endl;

    //可以通过类名去访问静态对象
    cout << person::m_a << endl;

    test();

    system("pause");

    return 0;
}