#include <iostream>
using namespace std;

int main()
{
    //一维数组

    int a[5];
    int b[5] = {10,20,30,40,50};
    int c[] = {10,20,30,40,50}; //数组定义必须有初始长度，

    a[0] = 10;
    a[1] = 20;

    cout << a[3] << endl; // 0
    cout << a[1] << endl;
    cout << b[1] << endl;
    cout << c[1] << endl;

    /*
    数组内容的调用和py列表的调用方法相同
    但是数组对元素数量有着严格的限制，不像py那样可以简单的添加删减
    对于未定义元素内容的元素用0来填充
    */

    for (int i = 0; i < 5; i++)
    {
        cout << b[i] << endl;
    }

    cout << "数组的内存大小: " << sizeof(b) << endl;
    cout << "数组中单个元素占用的内存大小" << sizeof(b[0]) << endl;
    cout << "数组中元素的数量 " << sizeof(b)/sizeof(b[0]) << endl;
    cout << size(b) << endl; //size用法相当于len
    //数组的相当于一个盒子，装着固定数量的对应类型的数据,是一个连续的内存空间，一个int占用4byte，那么5个int的数组占用 20byte ，这也就解释了为什么数组的元素数量是固定的
    
    cout << "数组的首地址为" << b << endl;
    cout << "数组的第一个元素地址为" << &b[0] << endl;
    //直接输出数组则会得到他的首个元素的内存地址

    system("pause");

    return 0;
}