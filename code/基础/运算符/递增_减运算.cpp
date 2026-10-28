#include <iostream>
using namespace std;

/*
在C++中，同样存在赋值运算符
+=
-=
%=
等...
*/

int main()
{
    //前置递增
    int a = 1;

    ++a; // 相当于 a+=1
    a++;

    cout << a << endl;

    --a; // 相当于 a-=1
    a--;

    //前置和后置的区别
    /*
    本质上是操作符顺序的问题
    ++a是先进行算术运算再进行表达式运算
    a++是先进行表达式运算再进行算术运算

    例如 b = a++ * 10
    会先进行 b=a*10 然后 a+=1
    例如 b = ++a * 10
    会先进行 a+=1 然后 b = (a+=1) *10
    */

    int b1 = a++; // b1=a a+=1
    cout << "后置" << b1 << a << endl;
    a--;

    int b2 = ++a; // b1=a= a+=1 先进行算术运算
    cout << "前置" << b2 << a << endl;

    system("pause");

    return 0;
}