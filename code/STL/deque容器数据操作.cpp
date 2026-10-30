#include <iostream>
#include <deque>
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
        deq.push_back(i);
    }
    
    deque<int>d2;
    d2 = deq;  //等号赋值

    deque<int> d3;
    d3.assign(deq.begin(),deq.end()); //assign区间赋值

    deque<int> d4;
    d4.assign(10,100); //通过assign赋值10个100

}

void test1()
{
    deque<int> deq;

    for (int i = 0; i < 5; i++)
    {
        deq.push_back(i);
    }

    if (deq.empty())
    {
        cout << "empty" << endl;
    }
    else
    {
        cout << "no empty" << endl;
    }

    cout << deq.size() << endl;
    //deque容器没有容量的概念，因为deque操作的是一个地址缓冲池
    deq.resize(3);  //容量变小多余尾部数据被抛弃
    deq.resize(10,0);  //扩容后往尾部填充0
    
}


int main()
{
    

    return 0;
}