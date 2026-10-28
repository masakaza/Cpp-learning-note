#include <iostream>
using namespace std;

int main()
{
    for (int i = 1; i <= 100; i++)
    {
        int a = i%10;
        int b = i/10;
        int c = i%7;

        if (a==7 || b==7 || c==0)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << i << endl;
        }
        
    }
    

    system("pause");

    return 0;
}