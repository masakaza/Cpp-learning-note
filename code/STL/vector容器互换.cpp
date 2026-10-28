#include <iostream>
#include <vector>
using namespace std;

/*
容器互换通常用于内存收缩
通过创建匿名对象来使得容器容量自动收缩

由于使用了拷贝v的方式构造了一个匿名对象
然后交换匿名对象和v使得v的容量缩小
当那一行代码执行结束后，获得大容量的匿名对象则会被编译器释放
从而收缩内存
*/

void test()
{
    vector<int> v;
    for (int i = 0; i < 10000; i++)
    {
        v.push_back(i);
    }

    cout << "capacity: " << v.capacity() << endl;
    v.resize(5);
    cout << "前容量: " << v.capacity() << endl;
    cout << "前大小: " << v.size() << endl;

    //创建匿名对象收缩内存
    vector<int>(v).swap(v);  //以拷贝v的方式创建一个匿名对象并交换

    cout << "后容量: " << v.capacity() << endl;
    cout << "后大小: " << v.size() << endl;

}

int main()
{
    test();

    return 0;
}