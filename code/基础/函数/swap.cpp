#include "swap.h"

void exchange(int a, int b)
{
    cout << "a= " << a <<endl;
    cout << "b= " << b <<endl;

    int temp = a;
    a = b;
    b = temp;

    cout << "a= " << a <<endl;
    cout << "b= " << b <<endl;
}