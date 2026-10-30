#include <iostream>
#include <stack>
using namespace std;

/*
stack栈容器，存取规则是先进后出
*/

void test()
{
    stack<int> s1;
    stack<int> s2;
    s1.push(10);
    s1.push(10);
    s1.push(10);
    s1.push(10);
    s1.push(10);  //添加数据

    s2 = s1; //等号赋值

    s1.pop(); //弹出顶部数据

    int temp = s1.top(); //返回顶部数据

    if (s1.empty())
    {
        cout << "empty " << endl;
    }
    else
    {
        cout << "none empty" << endl;
    }

    cout << s1.size() << endl;  //查看栈内部的大小
    
}

int main()
{
    

    return 0;
}