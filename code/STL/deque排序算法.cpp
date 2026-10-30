#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

/*
deque的构造方式和其他类似
不同的是他是一个双端读取队列
*/

void test()
{
    deque<int> deq;

    for (int i = 0; i < 5; i++)
    {
        deq.push_back(i);  //往末尾放入数据
    }

    for (int i = 0; i < deq.size(); i++)
    {
        //这两个方式都能通过索引来访问数据，at方法会检查是否越界
        cout << deq.at(i) << endl;
        cout << deq[i] << endl;
    }
    
    cout << deq.front() << endl; //读取头部位置的数据 (第一个元素)
    cout << deq.back() << endl; //读取尾部位置的数据(最后一个元素)


    deq.push_front(10); //往头部放入数据

    deq.pop_back(); //删除尾部数据（最后一个）
    deq.pop_front(); //删除头部数据(第一个)

    deq.insert(deq.begin(),5); //往迭代器指示的位置中插入数据
    deq.insert(deq.begin(),2,10); //往迭代器指示位置插入2个10
    deq.insert(deq.begin(),deq.begin()+1,deq.end()); //往迭代器指示位置插入区间的数据

    sort(deq.begin(),deq.end()); //通过sort算法来排序迭代器指定的区间位置的数据
    //sort算法对vector容器也适用

    deq.erase(deq.begin()); //删除迭代器指定位置的数据
    deq.erase(deq.begin(),deq.end()); //区间删除
    
    deq.clear(); //清空容器

}

int main()
{
    

    return 0;
}