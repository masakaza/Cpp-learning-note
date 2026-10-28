#include <iostream>
using namespace std;

class person
{
private:
    /* data */
public:
    person(int a,int b,int c);
    ~person();

    int m_a;
    int m_b;
    int m_c;
};

person::person(int a,int b,int c):m_a(a),m_b(b),m_c(c) //初始化列表
{

}

person::~person()
{
}

void test()
{
    person p(10,20,30);

    cout << p.m_a << endl;
    cout << p.m_b << endl;
    cout << p.m_c << endl;

}

int main()
{
    test();

    system("pause");

    return 0;
}