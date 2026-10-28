#include <iostream>
using namespace std;

/*
类模板的继承的语法和普通类继承的语法差别不大
权限问题也是同样的
普通类也可以作为模板类的父类来继承

因为在继承中子类创建的时候会创建父类，所以要显式传递类模板的类型进去
如果把子类也变成类模板的话，就能实现同时灵活调用子类和父类
*/

template<typename T>
class base
{
public:
    T m;
};


//在继承的时候要指定模板类的数据类型
class Son : public base<int>
{

};

//在写继承的时候把子类也变成类模板
template<typename T1,typename T2>
class son2 : public base<T2>
{
public:
    T1 obj;
    son2()
    {
        cout << "T1 " << typeid(T1).name() << endl;
        cout << "T2 " << typeid(T2).name() << endl;
    }
};

void test()
{

    Son s;

    son2<int,char> s2;

}


int main()
{
    test();   

    return 0;
}