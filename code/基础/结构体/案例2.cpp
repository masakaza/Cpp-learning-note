#include <iostream>
using namespace std;

 struct hero
 {
    string name;
    int age;
    string sex;
 };
 
hero people[5] = {
    {"Áõ±¸",23,"ÄĞ"},
    {"¹ØÓğ",22,"ÄĞ"},
    {"ÕÅ·É",20,"ÄĞ"},
    {"ÕÔÔÆ",21,"ÄĞ"},
    {"õõ²õ",19,"Å®"},

};

void bubbleage(hero* h,int h_num)
{
    hero temp;
    for (int i = 0; i < h_num-1; i++)
    {
        for (int j = 0; j < h_num-1-i; j++)
        {
            if (h[j].age > h[j+1].age)
            {
                temp = h[j+1];
                h[j+1] = h[j];
                h[j] = temp;
            }
            
        }
        
    }
    
}

void printinfo(const hero* h,int h_num)
{
    for (int i = 0; i < h_num; i++)
    {
        cout << "name: " << h[i].name << " age: " << h[i].age << " sex: " << h[i].sex << endl;
    }
    
}

int main()
{
    bubbleage(people,size(people));

    printinfo(people,size(people));

    system("pause");

    return 0;
}