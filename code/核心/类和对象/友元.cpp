#include <iostream>
using namespace std;

/*
如果两个类是互相依赖的关系 使用类对象作为成员时使用对象成员
如果只是简单的借用关系 使用指针或者引用作为类成员
*/

class building;

class goodgay
{
private:
    building* b1;
public:
    goodgay(/* args */);
    ~goodgay();

    void visit();
};

class building
{
//通过friend声明全局函数是友元，这个函数可以访问类中的私有属性
friend void goodboy(building& bud);
//通过friend声明类是友元，使得这个类可以访问私有属性
friend class goodper;
//通过friend声明一个类中的成员函数是友元 使这个成员函数能访问私有属性
friend void goodgay::visit();

private:
    string bedroom;
public:
    building();
    string livingroom;
};

building::building()
{
    livingroom = "keting";
    bedroom = "woshi";
}

class goodper
{
private:
    building* b;
public:
    goodper();
    ~goodper();
    void visit()
    {
        cout << "访问" << b->livingroom << endl;
        cout << "访问" << b->bedroom << endl;
    }

};

goodper::goodper()
{
    b = new building;
}

goodper::~goodper()
{
    if (b != NULL)
    {
        delete b;
    }
    
}

goodgay::goodgay(/* args */)
{
    b1 = new building;
}

goodgay::~goodgay()
{
    if (b1 != NULL)
    {
        delete b1;
    }
}

void goodgay::visit()
{
    cout << "访问" << b1->bedroom <<endl;  //该成员函数为友元所以可以访问类中的私有属性
}

//全局函数作友元
void goodboy(building& bud)
{
    cout << "访问" << bud.bedroom << endl;
}

void test()
{
    building b;
    goodboy(b);

    goodper pe;
    pe.visit();

    goodgay g;
    g.visit();
}

int main()
{
    test();

    system("pause");

    return 0;
}