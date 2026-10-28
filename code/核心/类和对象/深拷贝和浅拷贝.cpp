#include <iostream>
using namespace std;

/*
浅拷贝只复制了对象的内存指针信息，并不会开辟内存，会导致对象释放时导致堆区内存的重复释放从而崩溃
深拷贝是在堆区开辟一块新的内存空间来存放变量
*/

class person
{
public:
    int age;
    person();
    person(int age);
    person(const person& p); //拷贝构造函数
    ~person();
    int* high = new int(180);
};


person::person()
{
    cout << "无参" << endl;
}

person::person(int ag)
{   
    age = ag;
    cout << "有参" << endl;
}

//实现拷贝构造函数解决浅拷贝的问题
person::person(const person& p)
{
    cout << "拷贝" << endl;
    age = p.age;
    high = new int(*p.high); //深拷贝操作申请出一块新的内存来使用
}

person::~person()
{   
    if (high != NULL)
    {
        delete high;   //编译器默认提供的拷贝函数是浅拷贝，只会复制内存指针指向，不会开辟新的堆区内存，会导致同一块内存重复释放
        high = NULL;
    }
    
    cout << "out" << endl; 
}

void test()
{
    person p1(18);
    person p2=p1;
    cout << p1.age << *p1.high << endl;
    cout << p2.age << *p2.high << endl;

}


int main()
{
    test();

    system("pause");

    return 0;
}