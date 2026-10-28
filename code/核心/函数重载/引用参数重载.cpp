#include <iostream>
using namespace std;


//当引用作为参数重载函数
void test(int&)
{
    cout << 1 << endl;
}
 
/*
因为int&传进函数内部后是可以更改的，const int&进入函数后只能读取不能修改 ，所以函数对外的参数要求是不一样的
一个能读能写，一个只读不写
所以能作为重载函数
指针作为参数的时候也能这样理解
*/

void test(const int&)
{
    cout << 2 << endl;
}


//函数的重载区分只会看必要参数，默认参数不参与重载函数的区分

void test1(int a , int b = 10)
{
    return;
}

void test1(int a)
{
    return;
}

int main()
{
    int a = 10;
    test(a);
    test(10);  //因为int& = 10非法，所以编译器会把常量重载到 const int&

    // test1(10);  //报错，只传入10的话能调用 第一个或者第二个 因为第一个的其他参数是默认参数

    system("pause");

    return 0;
}