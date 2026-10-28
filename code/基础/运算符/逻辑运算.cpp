#include <iostream>
using namespace std;

/*
逻辑运算（与或非），每个数值二进制数进行逻辑运算，这里用bool的0和1代替

在C++中除了0都为真
*/

int main()
{
    int a = 10; 
    int b = 10; 

    cout << !a << endl; //! 为非门   !1 = 0
    cout << (a && b) << endl; //&& 为与门  1 && 1 = 1
    cout << (a || b) << endl; // ||为或门  1 || 1 = 1

    system("pause");

    return 0;
}