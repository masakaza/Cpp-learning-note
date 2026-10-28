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
    vector<int> v1;
    for (int i = 0; i < 5; i++)
    {
        v1.push_back(i);
    }

    if (v1.empty())
    {
        cout << "v1空" << endl;
    }
    else
    {
        cout << "v1不空" << endl;
    }
    
    cout << "容量" << v1.capacity() << endl;
    cout << "大小" << v1.size() << endl;

    //容量永远大于等于大小 
    

    //vector更改容器大小
    v1.resize(15);
    printvector(v1); //如果扩容，多余的地方将会用默认数据填充

    v1.resize(3);
    printvector(v1); //如果减小容量，则会自动删除末尾多余的参数 
}

int main()
{
    test();

    return 0;
}