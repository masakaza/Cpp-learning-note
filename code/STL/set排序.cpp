#include <iostream>
#include <set>
using namespace std;

/*
通过仿函数可以重新定义排序规则
set默认排序从小到大
当传入自定义类型的时候
要通过自定义排序类来定义排序规则
*/

class person;

class mycompare
{
public:
    bool operator()(int v1,int v2)
    {
        return v1 > v2;
    }
};

//自定义数据类型比较规则
class mycom
{
public:
    bool operator()(const person& p1 , const person& p2)
    {}
};

void test()
{
    set<int,mycompare> s1;  //通过传入自定义排序类（带对比仿函数）来改变排序规则

    //set容器插入数据只有insert
    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);
    s1.insert(50);

}

int main()
{
    

    return 0;
}