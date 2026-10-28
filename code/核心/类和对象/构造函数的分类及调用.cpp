#include <iostream>
using namespace std;

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
    //括号法
    // person p; //调用默认构造函数
    // person p1(10);
    // person p2(p1);

    //下面这行代码编译器会认为是一个函数的声明
    // person p();

    // //显示法
    // person p; //调用默认构造函数
    // person p1 = person(10);
    // person p2 = person(p1);

    // person(10); //匿名对象，当这行代码执行完后系统会自动回收匿名的对象
    // person(p2); //等价于 person(p2) == person p2

    //隐式法
    person p3 = 10;
    person p4 = p3; //相当于 person p4 = person(p3)
}

int main()
{
    test();

    system("pause");

    return 0;
}