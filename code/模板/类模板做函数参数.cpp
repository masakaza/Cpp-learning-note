#include <iostream>
using namespace std;

/*
可以通过typeid(class)来看推断出的类型
当类模板当成函数参数传入的时候能用下面几种方式

1.指定传入类模板使用的模板类型
2.使用 类型模板 来推断类模板中所使用到的类型
3.直接用类似函数模板的方式来把整个传入参数进行模板化

类模板在被当成参数的时候的语法跟之前相似，可以加const
类模板在使用的过程中也存在值传递和引用的方式
*/

template<typename nametype,typename agetype>
class person
{
private:
    nametype name;
    agetype age;
public:
    person(nametype,agetype);
    ~person();
    void show();
};

//模板类的类外定义方式，要使用模板具体化的方式来定义函数
template<typename nametype,typename agetype>
person<nametype,agetype>::person(nametype n,agetype a)
{
    name = n;
    age = a;
}

template<typename nametype,typename agetype>
person<nametype,agetype>::~person()
{
}

template<typename nametype,typename agetype>
void person<nametype,agetype>::show()
{
    cout << name << "  " << age << endl;
}


//指定类模板的传入类型
void printperson(person<string,int>& p)
{
    p.show();
}

//类模板的传入参数模板化
template<typename T1 ,typename T2>
void printperson1(person<T1,T2>& p)  //编译器会自动推断类模板的传入参数
{
    cout << "T1: " << typeid(T1).name() << endl;
    cout << "T2: " << typeid(T2).name() << endl;
    p.show();
}

//像使用模板函数一样，把整个类参数类型模板化
template<typename T>
void printperson2(T& obj)
{
    cout << "T: " << typeid(T).name() << endl;
    obj.show();
}

void test()
{
    person<string,int>p("abc",100);
    printperson(p);

    printperson1(p);

    printperson2(p);
}

int main()
{
    test();

    return 0;
}