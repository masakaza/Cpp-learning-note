#include <iostream>
using namespace std;

#define day 7 //定义一个宏常量


//常量定义后不可修改

int main()
{
    cout << "day常量为 " << day << endl;

    const int month = 12;

    cout << "month的常量为 " << month << endl;

    system("pause");

    return 0;
}