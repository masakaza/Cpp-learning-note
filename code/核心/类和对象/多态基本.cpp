#include <iostream>
using namespace std;

/*
多态的实现条件：
父类定义一个虚函数
子类重写父类的虚函数

通过父类的指针或者对象来指向不同的子类对象来执行子类的对象
*/

/*
多态的原理：

在父类创建虚函数后，父类会生成一张虚函数指针表（vfptr），这个表中会存储父类中虚函数的地址
当子类继承父类后，虚函数表也会被继承，当子类重写虚函数，那么子类中继承的父类的表的虚函数地址会被更换成子类的虚函数的地址

当实现多态时
通常是创建一个父类类型的引用或者指针 并且指向子类
每个父类和子类对象中都会含有一张虚函数表，当指针指向对象时，这个指针就同时指向了对象的虚函数表
当调用虚函数的时候，编译器会根据虚函数表中的地址去访问对应的对象的虚函数
*/

class animal
{
private:
    /* data */
public:
    //虚函数
    virtual void speak()
    {
        cout << "动物在说话" << endl;
    }
};

class dog : public animal
{
private:
    /* data */
public:
    void speek()
    {
        cout << "bark" << endl;
    }
};

class cat : public animal
{
private:
    /* data */
public:
    void speak()
    {
        cout << "miao" << endl;
    }
};

//早绑定，在编译阶段确定了函数的地址

//当把父类的函数变成了虚函数后，编译器会根据传入的对象调用对应函数
void dospeak(animal& a)  //父类能接收子类对象
{
    a.speak();
}

void test()
{
    cat c;
    dospeak(c);

    dog d;
    dospeak(d);
}



int main()
{
    test();

    return 0;
}