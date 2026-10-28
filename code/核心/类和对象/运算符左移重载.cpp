#include <iostream>
using namespace std;

/*
一般不会利用成员函数来实现重载运算符操作
因为成员函数中是 p.operator<<(cout) : p << cout
一般利用全局函数来重载左移运算符
*/

class Person
{
friend ostream& operator<<(ostream& out,Person& p);
friend istream& operator>>(istream& in,Person p);

private:
    int m_a;
    int m_b;
public:
    Person(int,int);
    ~Person();
};

Person::Person(int a,int b)
{
    m_a = a;
    m_b = b;
}

Person::~Person()
{
}

//ostream是输出流类 使用引用的目的是整个程序中只能有一个ostream对象
ostream& operator<<(ostream& out,Person& p)
{
    cout << "A: " << p.m_a << " " << "B: " << p.m_b;
    return out;
}

//istram是输入流类 使用方法一致
istream& operator>>(istream& in,Person p)
{
    cout << "a: ";
    in >> p.m_a;
    cout << endl;

    cout << "b: ";
    in >> p.m_b;
    cout << endl;
    return in;
}



void test()
{
    Person p1(10,10);

    cout << p1 << endl;
    cin >> p1;
}

int main()
{
    
    test();

    system("pause");

    return 0;
}