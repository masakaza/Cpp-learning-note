#include <iostream>
using namespace std;

int main()
{
    //二维数组
    int arr[2][3] = {
        {1,2,3},
        {4,5,6}
    };

    int arr2[][3] = {
        {1,1,1},
        {1,1,1}
    };

    int a[][3]={1,1,1,1,1,1};

    cout << arr[0][1] << endl;
    cout << arr2[0][1] << endl;
    cout << a[0][1] << endl;

    cout << "数组的内存大小: " << sizeof(a) << endl;
    cout << size(a[0]) << endl; //size用法相当于len
    cout << size(a) << endl;
    /*
    二维数组的定义和一维数组大差不差，只不过首个内存地址的大小为其中一个一维数组的内存大小，总的内存大小计算和一维数组一样
    */

    system("pause");

    return 0;
}