#include <iostream>
using namespace std;

int main()
{
    int score[3][3] = {
        {100,100,100},
        {90,50,100},
        {60,70,80}
    };

    int result[3];
    string name[3] = {"张三","李四","王五"};

    for (int i = 0; i < size(score); i++)
    {   
        int temp = 0;

        for (int j = 0; j < size(score[0]); j++)
        {
            temp += score[i][j];
        }

        result[i] = temp;
        
    }

    cout << "三位同学的总分分别为 " << endl;

    for (int i = 0; i < size(result); i++)
    {
        cout << name[i] << " " << result[i] << endl ;
    }

    system("pause");

    return 0;
}