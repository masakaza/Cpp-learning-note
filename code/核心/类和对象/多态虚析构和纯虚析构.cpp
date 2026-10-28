#include <iostream>
using namespace std;

/*
虚析构的意义是 当使用父类的指针调用子类后，在释放指针的时候
如果父类虚构函数不是虚析构函数或者纯虚析构函数
那么只会执行父类的析构函数而不执行子类的析构函数导致内存泄漏
*/

class animal
{
private:
    /* data */
public:
    animal(/* args */);
    virtual ~animal() = 0; //虚函数和纯虚函数的用法和其他函数一样
};

animal::animal(/* args */)
{
}

//不同的是，类的构造函数和析构函数必须提供，否则编译器会报错
animal::~animal()
{
    cout << "父类析构" << endl;
}

class dog : public animal
{
private:
    /* data */
public:
    dog(/* args */);
    ~dog();
};

dog::dog(/* args */)
{
}

dog::~dog()
{
    cout << "dog析构 " << endl;
}


void test()
{
    animal* a = new dog();

    delete a;
}


int main()
{
    test();

    return 0;
}