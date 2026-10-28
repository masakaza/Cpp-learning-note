#include <iostream>
using namespace std;
// #include "Pot.h"
// #include "Circle.h"

class Pot
{
private:
    int p_x;
    int p_y;

public:
    Pot()
    {
        cout << "x" << endl;
        cin >> p_x;

        cout << "y" << endl;
        cin >> p_y;
    }

    int get_x()
    {
        return p_x;
    }

    int get_y()
    {
        return p_y;
    }

};

class Circle
{
private:
    int R;
    Pot center; //可以让另一个类作为当前类的成员

public:
    Circle()
    {
        cout << "半径" << endl;
        cin >> R;

    }

    int getR()
    {
        return R;
    }

    Pot get_center()
    {
        return center;
    }

};

void judge_location(Circle& c,Pot& p)
{
    int a = (p.get_x() - c.get_center().get_x())*(p.get_x() - c.get_center().get_x()) + ((p.get_y() - c.get_center().get_y()) * (p.get_y() - c.get_center().get_y()));
    int RR = c.getR() * c.getR();

    if (a == RR)
    {
        cout << "点在圆上" << endl;
    }
    else if (a > RR)
    {
        cout << "点在圆外" << endl;
    }
    else
    {
        cout << "点在圆内" << endl;
    }
    
    
    

}

int main()
{   
    cout << "设置点" << endl;
    Pot po;
    cout << "设置圆" << endl;
    Circle c;

    judge_location(c,po);

    system("pause");

    return 0;
}