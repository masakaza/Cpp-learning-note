#include <iostream>
using namespace std;

/*
堆区参数对象在浅拷贝的情况下会发生重复释放的问题，因此会进行深拷贝的操作
这里直接用重载=运算符来进行深拷贝操作
*/

class person
{
private:
    int* age;
public:
    person(int);
    ~person();
    int get_age();

    person& operator=(person& p)  //返回引用的一个重要原因是，如果返回的是值，函数在结束的时候会释放this指针指向的对象的内存，会导致重复释放问题
    {
        //深拷贝
        age = new int(*p.age);

        return *this;   //返回自身进行多次赋值操作
    }
};

person::person(int ag)
{
    age = new int(ag);
}

person::~person()
{
    if (age != nullptr)
    {
        delete age;
        age = NULL;
    }
    
}

int person::get_age()
{
    return *age;
}

void test()
{
    person p1(18);
    person p2(20);
    person p3(30);

    p3 = p2 = p1;   //此处为赋值运算

    cout << p1.get_age() << endl;
    cout << p2.get_age() << endl;
    cout << p3.get_age() << endl;
}

int main()
{
    test();

    system("pause");

    return 0;
}