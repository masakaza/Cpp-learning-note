#include <iostream>
using namespace std;

/*
内存全局区存放了程序的全局变量和静态变量，常量区
字符串常量和其他常量也放在这个地方
*/

/*
函数里面不返回局部变量的地址，因为局部变量存放于栈区中，当函数运行结束后会释放
其返回的指针地址为野指针
*/

//全局变量

int g_a = 10;
int g_b = 10;

const int c_g_a = 10;

int main()
{
    //局部变量,一般存放在栈区,不管是不是常量
    int a = 10;
    int b = 10;

    cout << "局部变量a的地址为 " << &a << endl;
    cout << "局部变量b的地址为 " << &b << endl;

    //静态变量
    /*
    静态变量的生命周期和全局变量相同，只会声明一次并在程序结束后释放，可以在局部变量前面加上 static使其变成静态变量
    */

    static int s_a = 10;  
    static int s_b = 10;
    cout << "静态变量a的地址为 " << &s_a << endl;
    cout << "静态变量b的地址为 " << &s_b << endl;

    cout << "全局变量a的地址为 " << &g_a << endl;
    cout << "全局变量b的地址为 " << &g_b << endl;

    //常量 
    cout << "字符串常量地址" << &"helloworld" << endl;
    const int c_a = 10;
    cout << "局部常量a的地址为 " << &c_a << endl;
    cout << "全局常量a的地址为 " << &c_g_a << endl;

    system("pause");

    return 0;
}