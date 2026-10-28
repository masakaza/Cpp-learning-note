#include <iostream>
#include "person.hpp"
using namespace std;

/*
在类模板的头文件声明中，由于类模板的成员函数只会在被实例化的时候才会创建
所以会出现链接失败等问题

一般使用头文件的时候，有两种方法
直接包含模板类实现的cpp文件,类实现的cpp文件中会包含h头文件
把模板类的定义和实现放进同一个hpp头文件里面
*/



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