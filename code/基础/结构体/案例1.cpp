#include <iostream>
#include <random>
using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> dist(1,100);

struct student
{
    string name;
    int score;
};

struct teacher
{
    string name;
    student stu[5];
};

void write_data(teacher* t,int t_num,int s_num)
{   
    string name_seed = "ABCDE";
    int score;
    for (int i = 0; i < t_num; i++)
    {
        t[i].name = "Teacher_";
        t[i].name += name_seed[i];

        for (int j = 0; j < s_num; j++)
        {
            score = dist(gen);

            t[i].stu[j].name = "Student_";
            t[i].stu[j].name += name_seed[j];
            t[i].stu[j].score=score;
        }
        
    }
    
}

void printinfo(const teacher* t,int t_num,int s_num)
{
    for (int i = 0; i < t_num; i++)
    {
        cout << " 老师 " << t[i].name << " 所带学生和分数为" << endl;
        for (int j = 0; j < s_num; j++)
        {
            cout << t[i].stu[j].name << " " << t[i].stu[j].score << "   ";
        }

        cout << endl;
        
    }
    
}

int main()
{
    teacher t[3];

    write_data(t,size(t),size(t[0].stu));

    printinfo(t,size(t),size(t[0].stu));

    system("pause");

    return 0;
}