#include <iostream>
using namespace std;

int main()
{
    for (int i = 1; i <= 9; i++) //ÐÐ
    {
        for (int j = 1; j <= i; j++) //ÁÐ
        {
            cout << j << "*" << i << "=" << j*i << " "  ;
        }
        
        cout << endl;
    }
    

    system("pause");

    return 0;
}