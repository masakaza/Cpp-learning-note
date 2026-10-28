#include <iostream>
using namespace std;

struct student
{
    string name;
    int age;
    int score;
};

struct teacher
{
    int id;
    string name;
    int age;
    student stu;
};


int main()
{
    teacher t;
    t.id = 10000;
    t.name = "老王";
    t.age = 50;

    t.stu.name = "小王";
    t.stu.age = 20;
    t.stu.score = 60;
    //通过点来访问teacher结构体中的student结构体，并更改相关元素

    //访问也是一样，用相同的方法来访问元素

    cout << t.id << endl;
    cout << t.name << endl;
    cout << t.age << endl;

    cout << t.stu.name << endl;
    cout << t.stu.age << endl;
    cout << t.stu.score << endl;


    system("pause");

    return 0;
}