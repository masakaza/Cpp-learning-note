#include <iostream>
using namespace std;

/*
结构体类似于py的字典，不同的点在于调用方法和用法，结构体不能随意在程序中增减对象，而且结构体内部能放入函数
*/

int main()
{
    struct Student
    {
        string name;
        int age;
        int score;
    }s3; //这样也可以创建结构对象
    
    Student student; //创建结构体对象，可以创建多个，用逗号隔开

    student.name = "lihua"; //更改对象内部数据
    student.age = 18;
    student.score = 100;

    cout << student.name << endl;
    cout << student.age << endl;
    cout << student.score << endl;

    cout << s3.name << endl;
    cout << s3.age << endl;
    cout << s3.score << endl;

    Student s2 = {"lihua",18,100}; //这种也可以创建结构对象

    system("pause");

    return 0;
}