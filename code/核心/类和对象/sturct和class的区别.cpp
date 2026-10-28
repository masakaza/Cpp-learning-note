#include <iostream>
using namespace std;

class c
{
    int a;   //默认是私有权限
};

struct aaa
{
    int b;   //默认是公共权限
};



int main()
{
    aaa n;
    c m;

    n.b = 123;
    m.a = 2130;   //默认是私有权限不可访问

    system("pause");

    return 0;
}