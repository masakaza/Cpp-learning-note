#include <iostream>
using namespace std;

int main()
{
    int* p = NULL; //空指针用于初始化指针 相当于a = None
    //空指针指向的位置是0，不可访问

    int* p1 = (int*)0x1100;
    //野指针指向的内存是非法的，因为内存没有被指针所申请，不可访问

    system("pause");

    return 0;
}