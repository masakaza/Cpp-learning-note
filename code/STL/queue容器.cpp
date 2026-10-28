#include <iostream>
#include <queue>
using namespace std;

/*
queue是一个队列数据结构
采用先进先出的结构

在queue中只有队头和队尾才能被外界访问到
因此队列不允许有遍历行为
*/

class person
{
private:
    /* data */
public:
    person(string,int);
    ~person();
    string name;
    int age;
};

person::person(string n , int a)
{
    name = n;
    age = a;
}

person::~person()
{
}

void test()
{
    queue<person> q;

    person p1("aaa",19);
    person p2("bbb",29);
    person p3("ccc",39);
    person p4("ddd",49);
    person p5("eee",59);

    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);
    q.push(p5);

    cout << "size:  " << q.size() << endl;
    while (!q.empty())
    {
        cout << "head: " << "name: " << q.front().name << " age: " << q.front().age << endl;
        cout << "end: " << "name: " << q.back().name << " age:  " << q.back().age << endl;

        //出队
        q.pop();
    }

    cout << "size: " << q.size() << endl;
}

int main()
{
    test();

    return 0;
}