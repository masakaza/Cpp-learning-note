#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int b = 20;
    int c = 0;

    c = (a > b ? a:b);  //表达式的bool值决定 ：选择的变量   1:0
    cout << c << endl;

    (a > b ? a:b) = 100; //三目表达式选择的是变量

    system("pause");

    return 0;
}