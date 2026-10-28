#include <iostream>
using namespace std;

/*
在类对象作为成员的时候
会先构造类成员(变量)，再构造当前类
因为类的构造是在栈区里面的
所以释放的时候先释放当前类 再释放类成员(对象)
*/

class Phone
{
private:
    /* data */
public:
    Phone(string name);
    ~Phone();
    string pname;

};

Phone::Phone(string name)
{
    pname = name;
}

Phone::~Phone()
{
}


class Person
{
private:
    /* data */
public:
    Person(string name,string pname);
    ~Person();
    string name;
    Phone phone;
};

Person::Person(string Name,string pname):name(Name),phone(pname)  //初始化列表的作用是告诉类要怎么创建对象
{
    
}

Person::~Person()
{
}

void test()
{
    Person p("qqq","motor");
    cout << p.name << endl;
    cout << p.phone.pname << endl;
}

int main()
{
    test();

    system("pause");

    return 0;
}