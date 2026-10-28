#include <iostream>
using namespace std;

#define PI 3.14

class circle
{

//公共权限
public:
    int m_r;

    float gei_circle()
    {
        return 2*PI*m_r;
    }

};

int main()
{
    circle c;
    int r;
    float result;
    cout << "输入圆的半径" << endl;
    cin >> r;

    c.m_r = r;
    result = c.gei_circle();
    cout << result << endl;

    system("pause");

    return 0;
}