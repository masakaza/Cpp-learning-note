#include <iostream>
using namespace std;

/*
在一般的开发中 成员的属性默认设为私有
这样设置后有利于我们控制属性的读写权限
*/

//同时给类成员设置私有属性可以验证数据有效性

class person
{

private:
    string name; //可读可写
    int age = 18; //只读  可写（范围在0~100之间)
    string idol; //只写

public:

    void get_set_name(int mode)  // 0 read 1 write
    {
        if (!mode)
        {
            cout << "姓名为" << name << endl;
        }
        else
        {
            cout << "输入名字" << endl;
            cin >> name;
        }
        
    }

    void get_age()
    {
        cout << "年龄为" << age << endl;
    }

    void set_age(int a)
    {
        if (a < 0 || a > 100)
        {
            cout << "输入有误，赋值失败" << endl;
            return;
        }

        age = a;
        
    }

    void write_iodl()
    {
        cout << "输入idol "  << endl;
        cin >> idol;
    }

};

//通过公共权限提供的方法来控制类成员的权限

int main()
{
    person p;

    p.get_set_name(1);
    p.set_age(160);   //验证数据的有效性，从保护类内成员
    p.get_set_name(0);
    p.get_age();
    p.write_iodl();
    string a;
    // a = p.idol; //idol只能写不能访问

    system("pause");

    return 0;
}