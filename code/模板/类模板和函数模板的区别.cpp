#include <iostream>
using namespace std;

/*
类模板不不能像函数模板那样能自动推导类型的使用方式
类模板中的参数列表能指定默认参数
*/

template<typename nametype,typename agetype = int> //模板类型可以指定默认参数，默认参数的用法和函数默认参数用法一样，只能在头部定义一次
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

int main()
{
    // person p("abc",18);  //类模板通常没有自动类型推导的行为，但是新的c++版本中有
    person<string,int> p("abc",18); //显式传入模板类型
    p.show();
     
    //模板默认参数的使用
    person<string> p1("sdljk",20); //类模板使用了默认参数因此可以不用指定类型
    p1.show();

    return 0;
}