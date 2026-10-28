#include <iostream>
using namespace std;

int main()
{
    for (int i = 0; i <= 100; i++)
    {
        if (i%2 == 0)
        {
            continue; // 跳过下面的代码直接进入下一个循环
        }
        cout << i << endl;
        
    } //输出奇数
    

    system("pause");

    return 0;
}