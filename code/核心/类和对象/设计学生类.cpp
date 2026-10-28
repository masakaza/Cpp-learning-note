#include <iostream>
using namespace std;

class Student
{

public:
    //类中的属性和行为统一称为成员
    //属性 成员属性/成员变量
    //行为 成员函数/成员方法

    string name;
    int id;

    void print_info()
    {
        cout << "学生姓名是" << name << endl;
        cout << "学生id是" << id << endl;
    }

};

int main()
{
    string name;
    int id;

    cout << "输入名字 " << endl;
    cin >> name;

    cout << "输入id " << endl;
    cin >> id;

    Student s;
    s.name = name;
    s.id = id;
    // s.cls_init();
    s.print_info();

    system("pause");

    return 0;
}