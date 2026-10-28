#include <iostream>
using namespace std;

void test(const int& a)
{
    // a = 10;
    cout << a << endl;
}

int main()
{   
    // int& f = 10; //引用的参数必须是一个可以被修改的值, 
    const int& f = 10; //引用前面加const后，这个f只有读的权限没有写的权限，所以这种定义是合法的
    //通过在引用前面加上const，可以访问一些 常量数值 比如const int a = 10 ，因为这种情况下引用只有只读权限

    int a = 10;

    test(a);

    system("pause");

    return 0;
}