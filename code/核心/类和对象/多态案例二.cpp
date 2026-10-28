#include <iostream>
using namespace std;

class drink_func
{
public:
    virtual void make_func() = 0;
};

class coffce : public drink_func
{
public:
    void make_func()
    {
        cout << "boiling water" << endl;
        cout << "cook coffce" << endl;
        cout << "take_in cup" << endl;
        cout << "add suger and milk" << endl;
    }
};

class tea : public drink_func
{
public:
    void make_func()
    {
        cout << "boiling water" << endl;
        cout << "cook tea leave" << endl;
        cout << "take_in cup" << endl;
        cout << "putin lemmon" << endl;
    }
};

void make(drink_func& c)
{
    c.make_func();
}
 
void test()
{
    coffce c;
    tea t;
    make(c);
    make(t);  
}

int main()
{
    test();

    return 0;
}