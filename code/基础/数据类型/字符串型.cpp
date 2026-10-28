#include <iostream>
#include <string> //使用C++风格字符串要加入这个头文件
using namespace std;

int main()
{
    char str1[] = "headf"; //C语言风格字符

    string str2 = "dsfasdhuiwfd"; //C++风格字符串 , 需包含一个头文件
    cout << sizeof(string) << endl;

    cout << str2 << endl;

    system("pause");

    return 0;
}