#include <iostream>
using namespace std;

/*
编译器通过重载函数是否需要传递参数来区分前置后置
传入int参数的是后置运算符，一般用int占位，在实际使用时不需要传入任何参数
*/

class MyInt
{
friend ostream& operator<<(ostream& out,MyInt my);

private:
    int num;
public:
    MyInt(/* args */);
    ~MyInt();

    MyInt& operator++()     //前置递增不传int ++p
    {
        num++;
        return *this;
    }

    MyInt operator++(int)   //后置递增用int占位重载 后置返回值的原因是，后置是先返回旧的对象再进行操作，在函数中会返回局部对象因此返回值 p++
    {
        MyInt temp = *this;
        num++;
        return temp;
    }   

};

MyInt::MyInt(/* args */)
{
    num = 0;
}

MyInt::~MyInt()
{
}

ostream& operator<<(ostream& out,MyInt my)
{
    out << my.num;
    return out;
}

void test()
{
    MyInt m;

    cout << ++m << endl;
    cout << m << endl;
}

void test1()
{
    MyInt m;

    cout << m++ << endl;
    cout << m << endl;

}

int main()
{
    test();
    test1();

    system("pause");

    return 0;
}