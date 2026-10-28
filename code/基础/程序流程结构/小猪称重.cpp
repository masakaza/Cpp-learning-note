#include <iostream>
using namespace std;

int main()
{
    float a = 0;
    float b = 0;
    float c = 0;

    cout << "输入a的重量" << endl;
    cin >> a;

    cout << "输入b的重量" << endl;
    cin >> b;

    cout << "输入c的重量" << endl;
    cin >> c;

    if (a > b)
    {
        if (a > c)
        {
            cout << "a最重" << endl;
        }
        else
        {
            cout << "c最重" << endl;
        }
        
    }
    else
    {
        if (b > c)
        {
            cout << "b最重" << endl;
        }
        else
        {
            cout << "c最重" << endl;
        }
        
    }
    

    system("pause");

    return 0;
}