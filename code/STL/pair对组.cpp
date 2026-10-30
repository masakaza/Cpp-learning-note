#include <iostream>
using namespace std;

/*
pair对组可以通过一个变量存储多个数据
通过first等数词可以访问对组的数据
*/

void test()
{
    pair<string,int>p("tom",18);
    cout << p.first << endl;
    cout << p.second << endl;

    pair<string,int> p = make_pair("Tom",20);
}

int main()
{
    

    return 0;
}