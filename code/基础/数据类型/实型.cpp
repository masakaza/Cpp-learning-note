#include <iostream>
using namespace std;

int main()
{
    /*
    float为单精度浮点数  7位有效数字
    double 为双精度浮点数   15-16位有效数字
    小数后面不加f默认为双精度浮点数
    */

    float pi = 3.14f; //数字末不加f默认
    double pi1 = 3.14;
    //默认情况下输出一个小数显示6位有效数字

    cout << "float的内存大小" << sizeof(float) << endl;  //4byte
    cout << "double的内存大小" << sizeof(double) << endl; //8byte

    system("pause");

    return 0;
}