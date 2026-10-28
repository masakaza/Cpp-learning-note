#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void printvector(vector<T> v)
{
    for ( auto i = v.begin(); i != v.end(); i++)
    {
        cout << *i << " ";
    }

    cout << endl;
    
}

void test()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    //像数组一样通过中括号来访问数据
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    //通过at()来访问元素
    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
    cout << endl;

    //at和[]的区别在于，at会检查是否越界，如果越界会直接返回错误而不会结束程序

    //通过这两个方式可以获取容器中开头和末尾的数据
    cout << "first " << v.front() << endl;
    cout << "end " << v.back() << endl;
    
    
}

int main()
{
    test();

    return 0;
}