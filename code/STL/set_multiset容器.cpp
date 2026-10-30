#include <iostream>
#include <set>
using namespace std;

/*
数据放入set容器后会自动排序
set容器不允许有重复数据
multiset容器允许有重复数据
如果传入自定义类型数据，需要传入排序类，知识点看 set排序
*/

void test()
{
    set<int> s1;

    //set容器插入数据只有insert
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);
    s1.insert(50);

    auto it = s1.find(10);  //在容器中查找指定元素并返回这个元素的迭代器，若不存在返回set.end()即尾后迭代器
    if (it == s1.end())
    {
        cout << "没有这个元素" << endl;
    }

    auto count = s1.count(10); //统计指定元素的个数

    //insert可以返回插入的状态
    auto i_bool = s1.insert(10);  //i_boll是一个pair对组

    if (i_bool.second)
    {
        cout << "插入成功" << endl;
    }
    else
    {
        cout << "插入失败" << endl;
    }
    
    


}

int main()
{
    

    return 0;
}