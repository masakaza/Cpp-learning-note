#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int b =3;

    cout << a / b << endl; //默认输出整数型，因此会舍弃小数点后面的数据
    //如果是两个浮点数计算，输出的类型为浮点型

    cout << a % b << endl; //%为取模操作,本质上是求余数
    //取模操作不能为浮点类型小数

    system("pause");

    return 0;
}