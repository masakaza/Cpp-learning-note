#include <iostream>
using namespace std;

int main()
{
    char ch = 'a'; //对于单个字符在内存中用ASCII编码保存
    //单引号只能对单个字符使用，占用1byte内存，双引号对字符串使用

    cout << "字符的内存空间 " << sizeof(char) << endl;
    cout << int(ch) << endl; //输出ch这个字符的ASCII编码

    //可以直接给变量赋值ASCII编码使其输出
    ch = 97; 
    cout << ch << endl;

    system("pause");

    return 0;
}