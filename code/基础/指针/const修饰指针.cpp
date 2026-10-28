#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    const int* p = &a;  //*p=a，const int *p 可以等价于const int a 所以指针指向的值不可以修改，指针指向的内存可以改
    int* const p = &a;  // const修饰的是p变量，也就是指针变量，所以指针指向的内存不可以更改，指向的值可以更改
    const int* const p = &a; //const修饰了指针指向值 和 指针变量，所以指针指向的值不能通过指针修改，指针地址也不能修改

    system("pause");

    return 0;
}