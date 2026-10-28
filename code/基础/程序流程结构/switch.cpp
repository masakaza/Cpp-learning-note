#include <iostream>
using namespace std;

int main()
{
    int score = 0;
    cout << "输入分数 " << endl;
    cin >> score;

    switch (score)
    {
    case 1:
        cout << "aaa" << endl;
        break;

    case 2:
        cout << "bbb " << endl;
        break;
    
    default:
        cout << "asdf " << endl;
        break;
    }

    system("pause");

    return 0;
}
/*
switch和if本质上都是条件判断语句，switch适合进行 选择菜单的制作，switch运行速度比if快而且资源消耗少
在制作选择菜单的代码里面，对比if代码显得更简单易懂
*/