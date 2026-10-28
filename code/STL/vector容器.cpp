#include <iostream>
#include <vector>
using namespace std;

/*
vector动态数组的原理
vector数组会提前预留比需要的内存空间多几个的数组
如果存入的数据到达一个上限值，那么vector会自动把数据拷贝到更大的空间去

vector内部数据的存储规则跟stack类似
front()是第一个元素，back()是最后一个元素
v.begin()迭代器是第一个元素的指针,v.end()是尾后指针
v.rend()迭代器指向第一个元素的前一个位置，v.rbegin()指向最后一个元素的位置

vector的迭代器是支持随机访问的迭代器
*/

template<typename T>
void printvector(vector<T> v)
{
    for (auto i = v.begin(); i != v.end(); i++)
    {
        cout << *i << " ";
    }
    
    cout << endl;
}

void test()
{
    //无参构造vector
    vector<int> v;

    for (int i = 0; i < 5; i++)
    {
        v.push_back(i);
    }
    
    // printvector(v);

    vector<int> v1(v.begin(),v.end()); //能把v.begin到v.end之间的数值全部传进去
    printvector(v1);

    vector<int>v2(10,100); //往vector中放入10个100

    vector<int>v3(v2); //把v2拷贝给v3
    printvector(v3);
}

//vector赋值
void test1()
{
    vector<int> v;

    for (int i = 0; i < 5; i++)
    {
        v.push_back(i);
    }

    //等号赋值
    vector<int> v1;
    v1 = v;
    printvector(v1);

    //assign
    vector<int> v2;
    v2.assign(v1.begin(),v1.end()); //assign是把容器内数据替换成具体值

    vector<int> v3(10,100);
    v3.assign(v2.begin(),v2.begin()+3); //v3 = {0,1,2}

    printvector(v3);

    vector<int> v4;
    v4.assign(10,100); //同样也是给v4内部赋值10个100
}

int main()
{
    test();
    test1();

    return 0;
}