#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a = 0;
    cout << "赋值整型：" << endl;
    cin >> a;
    cout << "整型变量为 " << a << endl;

    float f = 3.14f;
    cout << "整赋浮点：" << endl;
    cin >> f;
    cout << "浮点变量为 " << f << endl;

    char c = 'a';
    cout << "赋值字符：" << endl;
    cin >> c;
    cout << "字符变量为 " << c << endl;

    string s = "asdf";
    cout << "赋值字符串：" << endl;
    cin >> s;
    cout << "字符串变量为 " << s << endl;

    //bool值同理

    system("pause");

    return 0;
}