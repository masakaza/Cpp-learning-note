#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int* p = arr; // 指针获得数组中第一个数据的地址位置

    cout << "adsadf" << *p << endl;

    for (int i = 0; i < size(arr); i++)
    {
        cout << *p << endl;
        p++; // 指针根据类型每次移动固定内存大小来读取数组中的数据
    }
    

    system("pause");

    return 0;
}