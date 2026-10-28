#include <iostream>
using namespace std;

/*
new关键字可以申请内存到堆区上面，堆区的内存由自己控制创建和释放
可以理解为 我要new一个新的内存空间，然后定义一个指针去操控这个空间
*/

int* func()
{
    int* p = new int(20);   //指针本质是局部变量，放在栈区上面，通过new申请到的内存被放在堆区上面
    return p;
}

//如果局部变量未通过new关键字存放到堆区,那么在函数结束后内存将会被自动释放，返回的指针也就变成了野指针

//利用new开辟数组
void test()
{
    int* arr = new int[10]; //new返回的是数组的首地址，所以要用指针去接收他

    //数组释放
    delete[] arr; //如果不加[]只会释放数组首地址
}


int main()
{   
    test();
    int* p =func();
    cout << *p << endl;

    delete p; //通过delete 地址 来释放new申请的地址
    cout << *p << endl; //因为指针所指地址的内存已经释放了，会输出乱码

    system("pause");

    return 0;
}