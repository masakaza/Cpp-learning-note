#include <iostream>
using namespace std;

/*
指针在函数中有大作用，可以传入数组的地址作为指针来操控数组
*/

int main()
{
    int a = 10;
    //指针的定义,要声明指针所指的数据类型
    int* p;

    p = &a; //把指针指向a的地址

    cout << "a的地址" << &a << endl;
    cout << "p " << p << endl;

    *p=100; //通过指针来修改变量

    cout << "a " << a << endl;
    cout << "*p " << *p << endl;

    //指针在不同的类型下占用相同大小的内存空间 32bit为4byte 64bit为8byte
    cout << "int* " << sizeof(int*) << endl;
 
    system("pause");

    return 0;
}