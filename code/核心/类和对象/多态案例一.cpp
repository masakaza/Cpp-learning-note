#include <iostream>
using namespace std;

class calculator
{
protected:
public:
    calculator();
    ~calculator();
    virtual int opera();
    int num1;
    int num2;
};

calculator::calculator()
{
}

calculator::~calculator()
{
}

int calculator::opera()
{
    cout << "请指定操作" << endl;
    return 0;
}

class add : public calculator
{
public:
    int opera()
    {
        return num1 + num2;
    }
};

class mul : public calculator
{
public:
    int opera()
    {
        return num1 * num2;
    }
};

void test()
{
    calculator* c = new add; //指针是calculator类型的，如果不指向子类的对象，或者不实现多态，那么会默认调用calculate的opera函数
    c->num1 = 10;
    c->num2 = 10;

    cout << c->opera() << endl;

    delete c;

    //乘法同理
}

int main()
{
    test();

    return 0;
}