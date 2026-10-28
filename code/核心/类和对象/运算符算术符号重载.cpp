#include <iostream>
using namespace std;

/*
加减乘除等计算运算符重载都是类似的形式
运算符重载本质上也是一个函数，因此也可以发生函数重载
*/

class Person
{
friend Person operator+(Person& a, Person& b);
friend ostream& operator<<(ostream& out , Person& a);
friend Person operator+(Person& a, int b);

private:
    int m_a;
    int m_b;
public:

// 成员函数重载运算符
// Person operator+(Person& a)
//     {
//         Person c(0,0);
//         c.m_a = a.m_a + this->m_a;
//         c.m_b = a.m_b + this->m_b;

//         return c;

//     }

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


//全局重载运算符函数
Person operator+(Person& a, Person& b)
{
    Person c(0,0);
    c.m_a = a.m_a + b.m_a;
    c.m_b = a.m_b + b.m_b;

    return c;

}

//运算符重载发生函数重载
Person operator+(Person& a, int b)
{
    Person c(0,0);
    c.m_a = a.m_a + b;
    c.m_b = a.m_b + b;

    return c;
}

ostream& operator<<(ostream& out , Person& a)
{
    out << a.m_a << " " << a.m_b << endl;
    return out;
}


void test()
{
    Person p1(10,10);
    Person p2(10,10);

    Person p3 = p1 + p2;   

    cout << p3;

    //全局函数重载运算符本质调用
    // Person p3 = operator+(p1,p2);

    //成员函数重载运算符的本质调用
    //Person p3 = p1.operator+(p2);
}

int main()
{
    
    test();

    system("pause");

    return 0;
}