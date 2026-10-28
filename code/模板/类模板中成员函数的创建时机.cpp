#include <iostream>
using namespace std;

/*
类模板中的成员函数要等到类被实例化后才能在编译器中被创建
普通的类的成员函数不需要被实例化就会被创建
*/

class person1
{
private:
    /* data */
public:
    person1(/* args */);
    ~person1();
    void showperson1(){ cout << 111 << endl; }
};

person1::person1(/* args */)
{
}

person1::~person1()
{
}

class person2
{
private:
    /* data */
public:
    person2(/* args */);
    ~person2();
    void showperson2(){ cout << 222 << endl; }
};

person2::person2(/* args */)
{
}

person2::~person2()
{
}

template<typename T>
class myclass
{
private:
    /* data */
public:
    T obj;
    void func1(){obj.showperson1();}
    void func2(){obj.showperson2();}
};

void test()
{
    //只有当模板类被实例化后，他的成员函数才会在编译器中被创建
    myclass<person1>m;
    m.func1();
    m.func2();
}

int main()
{
    test();

    return 0;
}