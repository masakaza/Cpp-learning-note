#include <iostream>
using namespace std;

/*
函数重载的目的是增加函数的复用性
通过函数的参数类型不同，参数个数不同，参数顺序不同来自动判断使用哪个函数
*/

//函数重载要满足在同一个作用域下

void test(int)
{
    cout << 1 << endl;
}

void test(double)
{
    cout << 111 << endl;
}

void test(int,int)
{
    cout << 2312131 << endl;
}

void test(double,int)
{
    cout << "qqqq" << endl;
}

void test(int,double)
{
    cout << "aaaa" << endl;
}

//函数返回值不能作为函数重载的条件，因为编译器是根据传入函数的参数来判断载入哪个函数


int main()
{
    test(1); // 传入int类型
    test(1.123); //传入double类型
    test(1,1); //传入两个int类型
    test(1.23,1);
    test(1,1.232);
    //传入的两个参数的顺序不同

    system("pause");

    return 0;
}