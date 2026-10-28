#include <iostream>
#include "myarr.hpp"
using namespace std;

/*
知识点在hpp文件中
*/

//如果提供了有参构造函数，但是需要new 类数组的话则必须提供一个无参的构造函数
//因为new会把每个元素调用一次这个类的默认构造函数
class person
{
private:
    /* data */
public:
    person();
    person(int,string);
    ~person();
    int age;
    string name;
    person& operator=(const person&);
};

person::person()
{
}

person::person(int a,string n)
{
    age = a;
    name = n;
}

person::~person()
{
}

person& person::operator=(const person& p)
{
    age = p.age;
    name = p.name;

    return *this;
}

ostream& operator<<(ostream& out,person& p)
{
    out << "名字: " << p.name << "  age: " << p.age;
    return out;
}


template<typename T>
void printarr(myarr<T>& arr)
{
    for (int i = 0; i < arr.get_size(); i++)
    {
        cout << arr[i] << endl;
    }
    
}

void test01()
{
    myarr<int> arr1(5);
    // myarr<double> arr4(5);
    // myarr<int> arr2(arr1);
    // myarr<int> arr3(100);
    // arr3 = arr1;

    for (int i = 0; i < 5; i++)
    {
        arr1.add(i);
    }
    
    printarr(arr1);
    cout << arr1.get_arrnum() << endl;
    cout << arr1.get_size() << endl;

    myarr<int>arr2(arr1);
    cout << "arr2 输出" << endl;
    printarr(arr2);
    arr2.del();
    printarr(arr2);
}

void test()
{
    myarr<person> arr(5);
    person p1(18,"aaa");
    person p2(10,"aba");
    person p3(16,"caa");

    arr.add(p1);
    arr.add(p2);
    arr.add(p3);

    printarr(arr);
}

int main()
{
    test();

    return 0;
}