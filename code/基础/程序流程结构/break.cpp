#include <iostream>
using namespace std;

/*
break语句的用法和py中一样，这里只展示在switch的用法,break在switch中的用法相似
*/

int main()
{
    cout << "1.a" << endl;
    cout << "2.b" << endl;
    cout << "3.c" << endl;
    cout << "4.exit" << endl;

    int select;

    cout << "选择: " << endl;
    cin >> select;

    switch (select)
    {
    case 1:
        cout << "a" << endl;
        break;
    
    case 2:
        cout << "b" << endl;
        break;

    case 3:
        cout << "c" << endl;
        break;

    case 4:
        break;

    default:
        break;
    }

    system("pause");

    return 0;
}