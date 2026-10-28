#include <iostream>
using namespace std;

class person
{
protected:  //保护域 子类函数可以访问，外部不能访问
    string car;
private:    // 私有域 子类函数和外部都不能访问，只能类内部访问
    int passwd;
public:     //公共域 外部和子类均可访问
    string name;
    int age;

};

class student : public person
{
public:
    void func()
    {
        car = "qqqq";
        name = "123123";
        age = 123;
    }
};


int main()
{
    student s;
    s.func();
    s.name = "qqq";
    s.age = 123;


    system("pause");

    return 0;
}