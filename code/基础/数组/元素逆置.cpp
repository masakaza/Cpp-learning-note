#include <iostream>
using namespace std;

int main()
{
    int a[5] = {4,5,2,3,1};
    int b[5];

    for (int i = (size(a) - 1) , x=0; i >= 0; i--,x++)
    {
        b[x] = a[i];
    }

    for (int i = 0; i < size(b); i++)
    {
        cout << b[i] << endl;
    }

    system("pause");

    return 0;
}