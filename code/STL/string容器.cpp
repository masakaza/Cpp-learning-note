#include <iostream>
using namespace std;

/*
string是一个c++风格字符串，内部自动管理了C风格的Char*[]字符串
*/

void test()
{
    string s1; //默认的构造

    const char* str = "hello world";
    string s2(str); //传入char*类型字符
    
    cout << "s2= " << s2 << endl;
    string s3(s2); //拷贝构造字符串
    cout << s3 << endl;

    string s4(10,'a'); //创建10个指定字符的字符串
    cout << s4 << endl;
}

void test1()
{
    string s1 = "hellp";
    string s2 = s1;
    string s3;
    s3 = 'a'; //可以把char类型字符赋值给字符串类型

    string s4;
    s4.assign("hello "); //可以把括号内字符串赋值给s4
    cout << s4 << endl;
    
    string s5;
    s5.assign("abchjslee",5); //把字符串的前5个字符赋值给变量


}

int main()
{
    test1();

    return 0;
}