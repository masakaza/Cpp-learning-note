#include <iostream>
using namespace std;

void test(int a , int)  //后面的int是函数的占位参数
{
    cout << '1' << endl;
}

void test1(int a , int = 10)  //占位参数也可以有默认参数
{
    cout << '1' << endl;
}

int main()
{
    test(1,1); //调用函数的时候也要把占位参数给传入进去

    system("pause");

    return 0;
}