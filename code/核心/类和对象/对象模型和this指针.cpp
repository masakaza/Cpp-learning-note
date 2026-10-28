#include <iostream>
using namespace std;

/*
每个空对象会占用内存一个字节，是为了区分对象在内存的位置
成员变量和成员函数是分开存储的，静态成员不存储在类的对象上 
成员函数也不存储在类的对象上
*/

/*
this指针相当于python的self，this指针指向的是调用当前函数的对象
静态成员函数中不能用this指针，因为静态成员函数是属于类的不属于某个对象
在使用链式编程时，函数返回的一定要是当前对象的引用，不然会拷贝出一个新的临时对象
*/

class person
{
private:
    int a; //非静态成员的内存在类的对象上
    static int b; //静态成员内存不存储在类的对象上
    void func(){} //非静态成员函数不存储在类的对象上  
    static void func1(){} //静态成员函数不存储在类的对象上

    int age;
public:
    person(int age);
    ~person();
    void show()
    {
        cout << this->age << endl;
    }

    person& addage(person& p)  //返回当前对象的常量指针（引用对象），如果返回person值则会复制出一个副本，额外增加开销
    {
        this->age += p.age;
        return *this;  //返回调用当前函数的对象
    }

};

int person::b = 10;

person::person(int age)
{
    this->age = age;  //this指针指向调用函数的对象
}

person::~person()
{
}

void test()
{
    person p1(20);
    person p2(10);
    cout << sizeof(p1) << endl;
    p1.show();

    //链式编程
    p2.addage(p1).addage(p1).addage(p1);
    p2.show();
}

int main()
{
    test();

    system("pause");

    return 0;
}