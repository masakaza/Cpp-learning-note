#include <iostream>
using namespace std;

/*
和前面的一样，如果将结构体直接传入的话在函数内的改变不会影响原来的元素，但是如果把结构体内存地址传入到函数指针，则能改变原有元素
*/

struct student
{
    string name;
    int age;
    int score;
};

void print_student(student stu)
{
    stu.age = 28;
    cout << stu.age << endl;
}

void print_student1(student* stu)
{
    stu->score = 28;
    cout << stu->score << endl;
}

int main()
{
    student s;
    s.name = "张三";
    s.age = 20;
    s.score = 85;

    cout << s.age << endl;
    print_student(s);
    cout << s.age << endl;

    cout << s.score << endl;
    print_student1(&s);
    cout << s.score << endl;

    system("pause");

    return 0;
}