#include <iostream>
using namespace std;

/*
在继承方法前面加上virtual为虚继承
虚继承的时候，所有虚继承子类共享一个父类对象，从而解决了二异性的问题
在菱形继承中，最后面的子类会继承另外两个父类的对象，本质上就是animal的共享对象
*/

class animal
{
private:
    /* data */
public:
    animal(/* args */);
    ~animal();
    int age;
};

animal::animal(/* args */)
{
}

animal::~animal()
{
}

class sheep : virtual public animal
{
private:
    /* data */
public:
    sheep(/* args */);
    ~sheep();
};

sheep::sheep(/* args */)
{
}

sheep::~sheep()
{
}

class Tuo : virtual public animal
{
private:
    /* data */
public:
    Tuo(/* args */);
    ~Tuo();
};

Tuo::Tuo(/* args */)
{
}

Tuo::~Tuo()
{
}

class sheeptou : public sheep , public Tuo
{
private:
    /* data */
public:
    sheeptou(/* args */);
    ~sheeptou();
};

sheeptou::sheeptou(/* args */)
{
}

sheeptou::~sheeptou()
{
}

void test()
{
    sheeptou st;

    //菱形继承两个父类会有相同的数据，需要加作用域来区分
    st.sheep::age = 10;
    st.Tuo::age = 20;
    st.age = 30;


}


int main()
{
    

    return 0;
}