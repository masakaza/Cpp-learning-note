#include <iostream>
using namespace std;

int main()
{
    int num = 100;

    do
    {
        int a = num%10;
        int b = (num/10) % 10;
        int c = num/100;

        int result = a*a*a + b*b*b + c*c*c;
        // cout << result << endl;

        if (result==num)
        {
            cout << result << endl;
        }
        
        
        num++;

    } while (num<1000);
    

    system("pause");

    return 0;
}