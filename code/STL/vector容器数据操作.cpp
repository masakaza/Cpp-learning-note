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

void test1()
{
    vector<int> v1;
    for (int i = 0; i < 5; i++)
    {
        v1.push_back(i);  //存放数据
    }

    v1.pop_back(); //删除尾部数据

    v1.insert(v1.begin(),100);  //在提供的迭代器位置插入数据
    printvector(v1);

    v1.insert(v1.begin()+2,2,100); //在指定的位置上插入2个100
    printvector(v1); 

    v1.erase(v1.begin()); // 删除指定位置的数据
    printvector(v1);

    cout << v1.at(0) << endl;

    v1.erase(v1.begin()+3,v1.end());//通过区间删除数据
    printvector(v1);

    //清空容器
    v1.clear();
}


int main()
{
    test1();

    return 0;
}