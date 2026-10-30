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
    
    deque<int>deq_1(deq.begin(),deq.end());  //通过区间方式给容器赋值  

    deque<int>deq_2(10,100); //给容器赋值10个100

    deque<int>deq_3(deq_1); //通过copy的方式给容器赋值
    
}

int main()
{
    

    return 0;
}