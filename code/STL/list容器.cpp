#include <iostream>
#include <list>
using namespace std;

/*
list是一个链表
每个数据都是一个独立的节点
每个节点都会存储下一个节点的内存地址
链表可以快速进行数据的插入和删除操作
STL中的链表是个双向循环链表，也就是说他会同时存储上一个节点的内存地址和下一个节点的内存地址
*/

/*
这里只会写他的特殊用法，和其他容器的相同用法不会在这里写出
*/

void test()
{
    list<int> l1;

    for (int i = 0; i < 5; i++)
    {
        l1.push_back(i);
    }

    list<int>l2(l1.begin(),l1.end()); //通过区间来给链表赋值

    list<int>l3(10,100); //往里面插入10个100
    l3 = l1;

    //赋值操作和其他的一样
    //交换操作
    swap(l1,l2);

    l2.remove(2); //通过remove来删除所有匹配的数据


    l3.reverse(); //反转容器，把元素在容器内部的顺序翻转
    


}

int main()
{
    

    return 0;
}