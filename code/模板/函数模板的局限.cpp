#include <iostream>
using namespace std;

/*
函数模板的局限性在于，他不能进行未定义的操作，比如说两个自定义类的对比
但是能通过函数模板的具体化来实现
进行具体化的时候要在相同的函数前面加上template<>来声明具体化模板
同时函数传入的参数形式是要一样的,比如都必须都是引用
*/

class person
{
private:
    /* data */
public:
    person(int);
    ~person();
    int age;
};

person::person(int a)
{
    age = a;
}

person::~person()
{
}

//当传入的类型不能进行自定义操作的时候就会报错
template<typename T>
bool is_one(T& a,T& b)
{
    return a == b;
}

//模板函数的具体化
template<> bool is_one(person& a,person& b)
{
    if (a.age == b.age)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}


int main()
{
    int a = 10;
    int b = 10;
    
    if (is_one(a,b))
    {
        cout << 111 << endl;
    }
    
    person p1(18);
    person p2(20);

    if (is_one(p1,p2))
    {
        cout << 222 << endl;
    }
    

    return 0;
}