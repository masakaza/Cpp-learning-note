#include <iostream>
using namespace std;

/*
同名函数优先调用普通函数，可以通过用<>空模板来强制调用函数模板
函数模板也能发生函数重载，重载规则和普通函数的重载规则一样

如果能有更好的函数能匹配输入类型，会优先调用那个函数
比如输入两个char类型，int类型要发生一次转换，函数模板不用转换
则会优先调用函数模板
*/

template<typename T>
void test(T a,T b)
{
    cout << "函数模板调用"  << endl;
}

void test(int,int)
{
    cout << "普通函数调用" << endl;
}

int main()
{
    test(1,2); //通常默认调用普通函数
    test<>(1,2); //可以通过<>空模板来调用函数模板

    char a = 'a';
    char b = 'b';

    test(a,b); //函数模板适配性更好因此会优先调用函数模板
    

    return 0;
}