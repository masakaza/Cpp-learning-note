#include <iostream>
using namespace std;

/*
在类模板中使用友元的时候
可以通过在类内实现全局函数来实现
也可以和正常友元一样在 friend声明使用同一个模板的模板函数，和普通友元不同的是，这个类外全局函数是模板函数
但是使用模板类友元的时候要在模板类前面声明模板函数，或者在模板类中使用友元的时候同时使用模板声明
*/

//声明模板类
template<typename nametype,typename agetype>
class person;

//声明友元模板函数
template<typename nametype,typename agetype>
void showperson(person<nametype,agetype>& p);


template<typename nametype,typename agetype>
class person
{
// // 类内全局函数，在函数前面加上friend
// friend void showperson(person<nametype,agetype>& p)
// {
//     cout << p.name << "  " << p.age << endl;
// }

//全局模板函数的友元声明,和普通友元声明类似，不过使用的是模板函数
friend void showperson<>(person<nametype,agetype>& p);

//在友元声明的时候同时使用模板声明 该函数是模板函数
template<typename n,typename a>
friend void showperson1(person<n,a>& p);

private:
    nametype name;
    agetype age;
public:
    person(nametype,agetype);
    ~person();
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
void showperson(person<nametype,agetype>& p)
{
    cout << p.name << "  " << p.age << endl;
}

template<typename nametype,typename agetype>
void showperson1(person<nametype,agetype>& p)
{
    cout << p.name << "  " << p.age << endl;
}


void test()
{
    person<string,int> p1("abc",18);

    showperson1(p1);
}



int main()
{
    test();

    return 0;
}