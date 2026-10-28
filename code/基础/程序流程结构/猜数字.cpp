#include <iostream>
#include <random>
using namespace std;

int main()
{
    random_device rd; // 创建随机数种子
    mt19937 gen(rd()); // 创建随机数生成器 通过gen（seed）
    uniform_int_distribution<int> dist(1,100); // 创建整数分布器

    int x = dist(gen); // 通过随机数生成器在 整数分布器的范围中生成随机数
    
    int y = 0;
    while (y!=x)
    {
        cout << "输入猜测的数字： " << endl;
        cin >> y;

        if (y>x)
        {
            cout << "大了" << endl;
        }
        else if (y<x)
        {
            cout << "小了" << endl;
        }
        
    }

    while (true)
    {
        cout << "输入猜测的数字： " << endl;
        cin >> y;

        if (y>x)
        {
            cout << "大了" << endl;
        }
        else if (y<x)
        {
            cout << "小了" << endl;
        }
        else
        {
            break;
        }
    }

    cout << "回答正确" << endl;
    

    system("pause");

    return 0;
}