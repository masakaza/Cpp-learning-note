#include <iostream>
using namespace std;

/*
子类会继承父类全部的非静态成员，但是会隐藏父类的private权限成员，因此访问不到
子类会继承父类的pubilc和protected权限的对象
class B : public A  其中的A是父类
子类继承得到的权限三种都可以
其中 public继承 得到的父类对象不会改变本身在父类中的权限，也就是说public和protected权限的对象的权限不变
其余两种（private和protected）会使得从父类继承的对象得到相对应的权限

在构造子类时会先构造父类，两个类对象存放在栈区，因此构造和析构顺序和栈的规则一样
如果子类中重写了父类中存在的同名函数，那么则会隐藏父类的函数优先调用子类的函数
如果在非多态的函数中重写了父类的函数，两个函数的返回类型不同的情况下，同样会调用子类的函数

静态成员和非静态成员出现同名处理方法也是一样的，通过添加作用域来解决

*/

class animal
{
private:
    /* data */

protected:
    void prot()
    {
        cout << "animal_prot" << endl;
    }

public:
    animal(/* args */);
    ~animal();
    void eat();
    void walk();
    void same();
    void same(int);
    static void func()
    {
        cout << "animal_func" << endl;
    }
};

animal::animal(/* args */)
{
    cout << "父类构造" << endl;
}

animal::~animal()
{
    cout << "父类析构" << endl;
}

void animal::eat()
{
    cout << "rat" << endl;
}

void animal::walk()
{
    cout << "walk" << endl;
}

void animal::same()
{
    cout << "same_animal" << endl;
}

void animal::same(int)
{
    cout << "same_int" << endl;
}


class dog : public animal   //此处的public指的是dog把继承animal得到的对象的权限不变
{
private:
    /* data */
public:
    dog(/* args */);
    ~dog();
    void bark();
    void same();
    static void func()
    {
        cout << "dog_func" << endl;
    }
};

dog::dog(/* args */)
{
    cout << "子类构造" << endl;
    cout << sizeof(dog) << endl; //父类中所有非静态成员被继承（被创建）
}

dog::~dog()
{
    cout << "子类析构" << endl;
}

void dog::bark()
{
    cout << "bark" << endl;
}

void dog::same()
{
    cout << "same_dog" << endl;
    prot(); //属于protected权限对象（从父类继承），可以类内访问

}


class dog_p : private animal //从animal中继承得到的全部对象都变为private权限
{
private:
    /* data */
public:
    dog_p(/* args */);
    ~dog_p();
};

dog_p::dog_p(/* args */)
{
}

dog_p::~dog_p()
{
}



void test()
{
    dog d;

    //调用父类
    d.eat();
    d.walk();
    // d.prot(); //父类中属于protected权限对象 不可访问

    //调用子类专属
    d.bark();

    //重写父类函数
    d.same();
    d.animal::same();  //通过指定作用域来调用父类中的同名函数
    // d.same(int); //报错是因为类在继承的时候重写函数会把父类中所有的同名函数隐藏，因此不能通过类型重载调用父类的函数

    animal::func();
    dog::func();
    d.func();
    d.animal::func();
    dog::animal::func(); //可以通过类名访问的方式来进行访问
}

class test : public animal , public dog //多继承语法，如果遇到同名的对象也是通过作用域来访问
{
private:
    /* data */
public:
    test(/* args */);
    ~test();
};

test::test(/* args */)
{
}

test::~test()
{
}


void test1()
{
    dog_p d;

    //调用父类，通常会报错，因为从父类继承的对象是私有权限的，所以不能在外部直接调用
    // d.eat(); //因为是私有（保护）权限所以不可访问

}


int main()
{
    test();

    return 0;
}