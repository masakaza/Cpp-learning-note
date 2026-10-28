#include <iostream>
using namespace std;

/*
程序会默认提供三个函数
构造函数
析构函数
拷贝函数
如果我们定义了有参（无参）构造函数后，程序将不会提供构造函数

总的来说，person相当于 __init__ 在创建对象时会自动执行,构造函数可以重载，如果我们自己定义了person函数后，程序就不会提供其他__init__方法  
*/

class person
{
private:
    /* data */
public:
    person();
    person(int a);
    person(const person& p);
    int age;
    
};

person::person()
{
    cout << "无参构造函数" << endl;
}

//有参构造函数
person::person(int a)
{
    age = a;
    cout << 1 << endl;
}

//拷贝构造函数
person::person(const person& p)
{
    age = p.age;
    cout << 2 << endl;
}
//将其他对象的属性拷贝到这个对象上面

void test()
{
    person p(20);
    person p1(p);
}

void abb(person p1) //函数在使用值传递的时候 会复制一份 person p1 = p 而这个p是person类，因此是隐式的拷贝构造
{

}

void test1()
{
    person p;
    abb(p);
}

person abb1()
{   
    person p;
    return p; //在返回的时候函数会拷贝一份对象再返回
}

void test2()
{
    person p1 = abb1(); //新版本编译器不会调用拷贝函数，会直接把p1创建在p的位置上
}

int main()
{
    // test1();
    test2();

    system("pause");

    return 0;
}