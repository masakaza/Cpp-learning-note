#pragma once
#include <iostream>
using namespace std;

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