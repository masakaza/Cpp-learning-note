#include <iostream>
using namespace std;

int main()
{
    int pig[5] = {300,350,200,400,250};
    int fat_pig = 0;

    for (int i = 0; i < size(pig); i++)
    {
        if (pig[i] > fat_pig)
        {
            fat_pig = pig[i];
        }
        
    }

    cout << "最重的为 " << fat_pig << endl;
    
    system("pause");

    return 0;
}