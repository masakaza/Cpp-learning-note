#include <iostream>
using namespace std;

class cube
{
private:
    int H;
    int L;
    int W;
public:
    cube(int h,int l,int w);

    int calculateS()
    {
        return 2*H*L+2*H*W+2*W*L;
    }

    int calculateV()
    {
        return H*W*L;
    }

    int get_h()
    {
        return H;
    }

    int get_l()
    {
        return H;
    }

    int get_w()
    {
        return H;
    }

    bool is_same_byclass(cube& c)
    {
        if (H == c.get_h() && L == c.get_l() && W == c.get_w())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};

cube::cube(int h,int l,int w)
{
    H = h;
    L = l;
    W = w;
}

bool judge_cube(cube& a,cube& b)
{
    if (a.get_h() == b.get_h() && a.get_l() == b.get_l() && a.get_w() == b.get_w())
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

int main()
{
    cube c1(10,10,10);
    cube c2(10,10,10);

    cout << "面积" << c1.calculateS() << endl;
    cout << "体积" << c1.calculateV() << endl;

    bool ret = judge_cube(c1,c2);

    if (ret)
    {
        cout << "相等" << endl;
    }
    else
    {
        cout << "不相等" << endl;
    }

    bool ret1 = c1.is_same_byclass(c2);

    if (ret1)
    {
        cout << "相等" << endl;
    }
    else
    {
        cout << "不相等" << endl;
    }
    
    system("pause");

    return 0;
}