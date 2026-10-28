#include <iostream>
using namespace std;

/*
引用的本质是一个指针常量
所以可以通过后面的变量名来改变原来的值，但是不能修改指向（被引用的变量）
*/

int main()
{
    int a = 10;
    int& b =a; //引用相当于给变量取了别名，后续可以通过这个名字来修改原变量

    b = 20;

    cout << a << endl;

    //注意事项
    int c = 10;
    int d = 20;
    // int& q;  //引用必须要初始化，指向一个被引用的对象
    int& e = c;

    e = a; //赋值操作，并不是更改指向

    system("pause");

    return 0;
}