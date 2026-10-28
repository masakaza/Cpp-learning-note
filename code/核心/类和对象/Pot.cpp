#include "Pot.h"
#include <iostream>
using namespace std;

Pot::Pot()
{
    cout << "x" << endl;
    cin >> p_x;

    cout << "y" << endl;
    cin >> p_y;
}

int Pot::get_x()
{
    return p_x;
}

int Pot::get_y()
{
    return p_y;
}
