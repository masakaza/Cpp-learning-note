#include <iostream>
using namespace std;

/*
在重载其他关系运算符时也是相似的操作
*/

class person
{
friend bool operator==(const person& a,const person& b);

private:
    int age;
    string name;
public:
    person(string,int);
    ~person();
};

person::person(string n, int a)
{
    age = a;
    name = n;

}

person::~person()
{
}

//关系运算符通常用于进行比较判断，所以返回bool
bool operator==(const person& a,const person& b)
{
    if (a.age == b.age && a.name == b.name)
    {
        return true;
    }

    return false;
    
}


void test()
{
    person p1("Tom",18);
    person p2("Alex",20);

    if (p1 == p2)
    {
        cout << "相等" << endl;
    }
    else
    {
        cout << "不相等" << endl;
    }
    
}

int main()
{
    test();
    
    return 0;
}