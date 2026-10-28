#include <iostream>
using namespace std;


//引用可以作为函数参数进行传入，和指针类似实现对原参数的修改
void swap(int& a,int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

//引用也可以作为函数的返回值
int& test()
{
    static int a = 20; //函数需要返回静态变量
    return a;
}
//因为引用的本质是指针常量，所以返回的值可以近似看作一个指针
//因此引用返回的必须是静态变量，不能是局部变量

int main()
{
    int a = 10;
    int b = 20;

    swap(a,b);
    cout << a << endl;
    cout << b << endl;

    int& c = test();
    cout << c << endl;
    
    //如果函数返回的是引用，那么这个函数也可以作为左值
    test() = 40;  //因为返回的是一个常量指针,是静态变量的地址本身，所以可以直接这样更改指针所指向的值，等价于 [&a = test()], a=40
    cout << c << endl; //因为c指向的地址和静态变量a指向的地址相同，所以输出40

    system("pause");

    return 0;
}