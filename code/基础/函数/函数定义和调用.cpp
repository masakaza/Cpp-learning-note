#include <iostream>
using namespace std;

/*
函数必须写在main函数前面，否则就需要在main函数前进行函数的声明
*/

//函数声明

int sum(int a,int b);
void none_ret();


int sum(int a,int b)
{
    return a*b;
}
/*
函数前面必须声明返回值的类型，如果没有返回值用void
*/

//无返回函数
void none_ret()
{
    return;
}

int main()
{
    int result;
    int a;
    int b;
    cout << "1" << endl;
    cin >> a;

    cout << "2" << endl;
    cin >> b;

    result=sum(a=a,b=b);
    cout << result << endl;

    system("pause");

    return 0;
}