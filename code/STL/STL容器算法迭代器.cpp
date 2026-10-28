#include <iostream>
#include <vector> //导入vector容器库
#include <algorithm> //导入标准算法库
using namespace std;

/*
vector存放内置数据类型

最常用的容器
容器 vector 可以理解为动态数组
算法 for_rach 遍历算法
迭代器 vector<int>::iterator
*/

void printdata(int a)
{
    cout << a << endl;
}

void test()
{
    //创建一个vector容器（数组）
    vector<int> v;

    //使用push_back插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    // //第一种遍历方式
    // //通过迭代器访问容器中的数据
    // vector<int>::iterator itBegin = v.begin(); //起始迭代器，可以理解为指向第一个元素的指针
    // vector<int>::iterator itEnd = v.end();  //结束迭代器，可以理解为尾后指针

    // while (itBegin != itEnd)
    // {
    //     cout << *itBegin << endl;
    //     itBegin++;
    // }
    
    // //第二种遍历方式
    // for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    // {
    //     cout << *it << endl;
    // }
    // //其运行逻辑和第一种相同

    //第三种遍历方式 利用STL提供的算法遍历
    for_each(v.begin(),v.end(),printdata); //最后的操作函数不加括号的意义是把函数作为参数传入
    //for_each接收 起始迭代器，结束迭代器，操作


}

//vector存放自定义数据类型
class person
{
public:
    person(string n,int a)
    {
        name = n;
        age = a;
    }
    string name;
    int age;
};


void test1()
{
    vector<person> v;

    person p1("aaa",10);
    person p2("bbb",20);
    person p3("ccc",30);
    person p4("ddd",40);
    person p5("eee",50);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    for (auto i = v.begin(); i != v.end() ; i++)
    {
        cout << "name " << (*i).name << " age " << (*i).age << endl;
    }
    
}

void test2()
{
    vector<person*> v;

    person p1("aaa",10);
    person p2("bbb",20);
    person p3("ccc",30);
    person p4("ddd",40);
    person p5("eee",50);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    for (auto i = v.begin() ; i != v.end(); i++)
    {
        cout << "::name " << (*i)->name << " age " << (*i)->age << endl;
    }
    
}

//容器嵌套容器，类似多维数组
void test3()
{
    vector< vector<int> > v;

    //创建小容器
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    for (int i = 0; i < 5; i++)
    {
        v1.push_back(i+1);
        v2.push_back(i+1);
        v3.push_back(i+1);
        v4.push_back(i+1);
    }

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    
    int count = 1;
    for(auto it = v.begin(); it != v.end(); it++)
    {
        // *it 解引后是一个 vector<int> 容器

        for (auto i = (*it).begin(); i != (*it).end(); i++)
        { 
            cout << "容器: " << count << endl;
            cout << *i << endl;
        }
        
        count++;
    }

}


int main()
{
    // test();
    // test1();
    // test2();
    test3();

    return 0;
}