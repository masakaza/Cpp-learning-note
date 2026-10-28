#include <iostream>
using namespace std;

/*
空指针访问的意义是在不浪费空间的前提下使用类里面的函数
*/

class person
{
private:
    /* data */
public:
    person(/* args */);
    ~person();

    int age;

    void showclsname()
    {
        cout << "this is a person class" << endl;
    }

    void showpersonage()
    {
        if (this == NULL)
        {
            return;   
        }  //判断指针是否为空防止程序出错
        
        cout << "age is" << age << endl;  //在调用对象的成员时会默认在前面加上this指针，如果这个指针为空指针或者野指针，程序就会报错
    }
};

void test()
{
    person* p = NULL;

    p->showclsname();
    p->showpersonage();

}

int main()
{

    test();

    system("pause");

    return 0;
}