#include <iostream>
using namespace std;

struct Student
{
    string name;
    int age;
    int score;
};

int main()
{
    Student student = {"张三",18,100};
    Student* p = &student; //因为变量返回的是Student类型的 ，所以指针的类型也要是Student

    cout << "name " << p->name << endl;
    cout << "name " << (*p).name << endl;
    //上面两种方法都能通过指针来访问结构体变量中的内容

    system("pause");

    return 0;
}