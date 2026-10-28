#include <iostream>
using namespace std;

/*
 
*/

class person
{
private:
    /* data */
public:
    // person(/* args */);
    // ~person();

    int age = 10;
    mutable int a; //mutable关键字使得这个变量能在常函数中被修改

    //常函数
    void showperson() const    //这里的const修饰的是this指针，使this指针指向的值不可以被修改
    {
        // age = 100;
        a = 100; //使用mutable关键字后能在常函数中进行修改
    }

    void func()
    {
        age = 100;
        a = 1;
    } //普通函数会修改常对象无法修改的成员，因此常对象只能调用常函数
};

void test()
{
    //只读对象
    const person p{};  //因为const对象要是一个确定的值，因此类中的所有成员变量都要有一个确定的初始的值
    //或者给p后面加上 {} 会声明在创建对象时进行成员的初始化（使用默认的构造函数下）
    p.showperson();
    // p.age = 10; //在常对象中不能修改成员的值，除非用了mutable修饰
    p.a = 10;

    // p.func(); //常对象只能调用常函数，因为常对象不能随便对成员进行修改，常函数满足了这一点
}

int main()
{
    
    // test();

    system("pause");

    return 0;
}