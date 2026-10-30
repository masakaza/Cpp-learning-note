#include <iostream>
#include <map>
using namespace std;

/*
map容器内部存储的全是pair类型，所以要传入pair使用的模板
map和multimap的规则和set当中的规则一样
传入的pair对组中第一个数是key 后面的是value
类似py中的字典
可以通过map[key]来获得value
*/

/*
map会根据传入的key来进行排序
可以像set容器当中一样，通过自定义排序类的仿函数来自定义排序规则
*/

void test()
{
    map<int,int>m;

    m.insert(pair<int,int>(1,10));
    //map也可以通过remove来删除所有指定的元素

    auto ind = m.begin();

    cout << (*ind).first << "  " << (*ind).second << endl;  //数据读取的方式

    m.insert(pair<int,int>(1,10));
    m.insert(make_pair(2,20));
    m.insert(map<int,int>::value_type(3,30));

    //可以通过key来删除数据
    m.erase(1);
}

int main()
{
    

    return 0;
}