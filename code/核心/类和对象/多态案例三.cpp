#include <iostream>
using namespace std;

//零件
class CPU
{
private:
    /* data */
public:
    virtual void calculate() = 0;
};

class GPU
{
private:
    /* data */
public:
    virtual void display() = 0;
};

class MEMORY
{
private:
    /* data */
public:
    virtual void storage() = 0;
};

//厂商
class Intel : public CPU , public GPU , public MEMORY
{
public:
    void calculate()
    {
        cout << "Intel_calculate" << endl;
    }

    void display()
    {
        cout << "Intel_display" << endl;
    }

    void storage()
    {
        cout << "Intel_storage" << endl;
    }
};

class AMD : public CPU , public GPU , public MEMORY
{
public:
    void calculate()
    {
        cout << "AMD_calculate" << endl;
    }

    void display()
    {
        cout << "AMD_display" << endl;
    }

    void storage()
    {
        cout << "AMD_storage" << endl;
    }
};

//电脑
class Computer
{
private:
    CPU* c;
    GPU* g;  
    MEMORY* m;
public:
    Computer(CPU*,GPU*,MEMORY*);
    ~Computer();
    void work();
};

Computer::Computer(CPU* cpu,GPU* gpu,MEMORY* mem)
{
    c = cpu;
    g = gpu;
    m = mem;
}

Computer::~Computer()
{
}

void Computer::work()
{
    c->calculate();
    g->display();
    m->storage();
}

void test()
{
    AMD* a = new AMD();
    Intel* i = new Intel();

    Computer c1(a,a,a);
    c1.work();
    cout << "----------------------" << endl;

    Computer c2(a,i,a);
    c2.work();
    cout << "-----------------------" << endl;

    Computer c3(i,i,a);
    c3.work();

    delete a;
    delete i;
}



int main()
{
    test();

    return 0;
}