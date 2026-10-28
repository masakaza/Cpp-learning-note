#include <iostream>
using namespace std;

int main()
{
    //单个if语句
    
    int score = 0;

    printf("输入分数: ");
    /*
    printf和cout的区别在于输出会不会换行，cout会自动换行，printf不会
    */
    cin >> score;
    cout << "分数为 " << score << endl;

    if (score > 600)
    {
        cout << "分数大于设定值" << endl;
    }
    else if (score > 300)
    {
        cout << "多个条件测试" << endl;
    }
    
    else
    {
        cout << "分数小于设定值" << endl;
    }
    

    system("pause");

    return 0;
}