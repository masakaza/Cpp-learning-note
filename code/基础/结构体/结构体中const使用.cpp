#include <iostream>
using namespace std;


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

//可以在函数传入变量前面加入const修饰，防止原结构体中的元素被误更改
void print_student2(const student* stu)
{
    // stu->score = 28;
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