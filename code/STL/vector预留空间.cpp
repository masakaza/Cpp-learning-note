#include <iostream>
#include <vector>
using namespace std;

/*
通过reserve预留内存可以减少他重新开辟内存的次数
从而减少程序开销
*/

void test()
{
    vector<int> v;

    int num = 0;
    int* p =nullptr;

    //预留内存
    v.reserve(100000);

    for ( int i = 0; i < 100000; i++)
    {
        v.push_back(i);

        if (p != &v[0])
        {
            p = &v[0]; //因为每次内存开辟操作首地址都会变更，因此可以统计开辟次数
            num++;
        }
        
    }
    
    cout << "内存开辟了: " << num << endl;

}

int main()
{
    test();

    return 0;
}