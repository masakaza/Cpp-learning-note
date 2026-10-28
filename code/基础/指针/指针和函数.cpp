#include <iostream>
using namespace std;

/*
如果函数传入的是指针，那么指针所对应的值也会收到函数内部代码的改动影响
*/

void exchange(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;

    cout << "a= " << a <<endl;
    cout << "b= " << b <<endl;
}

void exchange_point(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;

    cout << "a= " << *a <<endl;
    cout << "b= " << *b <<endl;
}


int main()
{
    int num1 = 10;
    int num2 = 20;
    exchange(num1,num2);
    cout << "1  " << num1 << "  " << num2 << endl;

    exchange_point(&num1,&num2);
    cout << "2  " << num1 << "  " << num2 << endl;

    system("pause");

    return 0;
}



