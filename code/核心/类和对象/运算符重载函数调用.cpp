#include <iostream>
using namespace std;

/*
函数重载又叫仿函数
用法类似python的 __call__

<class>()可以创建一个匿名对象，方便调用class内部的函数，使用完立即释放
*/

class myadd
{
private:
    /* data */
public:
    myadd(/* args */);
    ~myadd();
    int operator()(int,int);
};

myadd::myadd(/* args */)
{
}

myadd::~myadd()
{
}

int myadd::operator()(int a,int b)
{
    return a+b;
}

void test()
{
    myadd add;
    int ret = add(10,10);  //类似python调用class的__call__


    cout << ret << endl;
    cout << myadd()(20,10) << endl;  //myadd()是匿名对象

}


int main()
{
    test();

    return 0;
}