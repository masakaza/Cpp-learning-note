#include <iostream>
using namespace std;

/*
比较运算符号和py都是相同的，这里只做部分例子
唯一不同的是，输出为bool值（0/1）
*/

int main()
{
    int a = 10;
    int b = 20;

    cout << (a == b) << endl;
    cout << (a >= b) << endl;
    cout << (a <= b) << endl;
    cout << (a != b) << endl;

    system("pause");

    return 0;
}