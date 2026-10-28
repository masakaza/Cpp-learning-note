#include <iostream>
using namespace std;

/*
使用 虚函数 = 0 来定义纯虚函数
如果类中含有纯虚函数则该类为抽象类
抽象类无法实例化对象，子类必须要重写纯虚函数，否则也会变成抽象类
*/


class animal
{
private:
    /* data */
public:
    //纯虚函数
    virtual void speak() = 0;
    //只要有纯虚函数就是抽象类
    //抽象类无法实例化对象
};

//子类也要重写父类中的纯虚函数，否则也会变成抽象类
class dog : public animal
{
private:
    /* data */
public:
    void speak()
    {
        cout << "bark" << endl;
    }
};

void test()
{
    dog d;
    animal* d_p = &d;

    d_p->speak();
}


int main()
{
    test();

    return 0;
}