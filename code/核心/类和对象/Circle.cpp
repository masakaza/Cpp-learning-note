#include "Circle.h"
#include <iostream>
using namespace std;

Circle::Circle()
{
    cout << "°ë¾¶" << endl;
    cin >> R;

}

int Circle::getR()
{
    return R;
}

Pot Circle::get_center()
{
    return center;
}

