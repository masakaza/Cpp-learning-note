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
    
    Student stuarr[3] = 
    {
        {"张三",18,100},
        {"李四",28,99},
        {"王五",38,66}
    };  //可以像数组一样传入多个元素

    stuarr[2].name = "赵六";
    stuarr[2].age = 80;
    stuarr[2].score = 60;
    //用类似修改数组的方法来修改结构体内的元素

    for (int i = 0; i < size(stuarr); i++)
    {
        cout << stuarr[i].name << endl;
        cout << stuarr[i].age << endl;
        cout << stuarr[i].score << endl;
    }
    

    system("pause");

    return 0;
}