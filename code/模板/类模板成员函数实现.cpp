#include <iostream>
using namespace std;

/*
类模板的成员函数在类外实现的时候要同时声明模板，使用模板参数
person<nametype,agetype>：：
表示类模板的作用域下
*/

template<typename nametype,typename agetype>
class person
{
private:
    nametype name;
    agetype age;
public:
    person(nametype,agetype);
    ~person();
    void show();
};

//模板类的类外定义方式，要使用模板具体化的方式来定义函数
template<typename nametype,typename agetype>
person<nametype,agetype>::person(nametype n,agetype a)
{
    name = n;
    age = a;
}

template<typename nametype,typename agetype>
person<nametype,agetype>::~person()
{
}

template<typename nametype,typename agetype>
void person<nametype,agetype>::show()
{
    cout << name << "  " << age << endl;
}

void test()
{
    person<string,int>p1("abc",18);  //在创建类对象的时候要显式指定传入的参数类型
    p1.show();
}

int main()
{
    test();

    return 0;
}