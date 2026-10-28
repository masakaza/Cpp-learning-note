#include <iostream>
using namespace std;

int main()
{
    //短整型 2byte
    short num1 = 10;

    //整型 4byte
    int num2 = 10;

    //长整型 4byte 在linux中是8byte(64bit系统)
    long num3 = 10;

    // 8byte
    long long num4 = 10;


    //sizeof里面可以放数据类型也可以放变量，在实际项目中可以通过这个来检查变量占用内存大小从而优化内存的使用
    cout << "short占用内存空间为 " << sizeof(short) << endl;
    cout << "int占用内存空间为 " << sizeof(int) << endl;
    cout << "long占用内存空间为 " << sizeof(long) << endl;
    cout << "long long占用内存空间为 " << sizeof(long long) << endl;

    system("pause");

    return 0;
}