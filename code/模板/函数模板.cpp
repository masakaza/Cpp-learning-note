#include <iostream>
using namespace std;

/*
模板可以粗略理解为是 类型的变量，编译器能通过输入来适配不同类型
一个template声明下面只能跟着一个使用未定义参数类型的函数模板

template中可以定义多个未定义的类型
但是相同名字的未定义类型在传入参数时使用的类型必须是一样的
T类型在传入时候只能有一个类型，即 当T=int时候不能传其他类型的参数
如果有T，U两个未定义类型,T和U的传入类型可以不同也可以相同 

函数模板在推导的过程中不能发生隐式类型转换，比如char转int
*/

//模板的声明
template<typename T>  //typename和class的效果是一样的
void T_exchange(T& a,T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<typename T> 
T tadd(T a, T b)
{
    return a+b;
}

template<typename T,typename U>
void tem_test(T& a , U& u)
{
    return;
}

template<typename T>
void func()
{
}
void exchange(int& a , int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void exchange(double& a,double& b)
{
    double temp = a;
    a = b;
    b = temp;
}

//不使用函数模板
void test()
{
    int a = 10;
    int b = 10;
    exchange(a,b);
    cout << a << "  " << b << endl;

    double d_a = 10.5;
    double d_b = 20.6;
    exchange(d_a,d_b);
    cout << a << "  " << b << endl;

    
}

//使用函数模板
void test1()
{
    //自动类型推导
    int a = 10;
    int b = 20;
    T_exchange(a,b);
    cout << a << " " << b << endl;

    double d_a = 10.4;
    double d_b = 3.62;
    T_exchange(d_a,d_b);
    // cout << a << ' ' << endl;
    cout << d_a << " " << d_b << endl;

    //显式指定类型推导
    T_exchange<int>(a,b);
    T_exchange<double>(d_a,d_b);
    cout << a << " " << b << endl;
    cout << d_a << " " << d_b << endl;
}

int add(int a , int b)
{
   return a+b; 
}

void test2()
{
    int a;
    int aa;
    double b;
    // T_exchange(a,b); //两者推导出的类型不一致会报错

    tem_test(a,b); //T和U是两个不同的推导类型，因此不会报错

    // func(); //函数模板使用到的未定义类型必须被指定，否则会报错
    func<int>(); //可以用显式指定推导类型来调用函数模板

    char c = 'a';

    add(a,c); //普通函数能发生隐式类型推导，能自动把char转换成int

    // tadd(a,c); //模板函数不能发生隐式类型推导，不能自动把char转换成int
    tadd<int>(a,c); //但是当我们显式指定类型推导后，会发生隐式类型转换
}

int main()
{
    test1();

    return 0;
}