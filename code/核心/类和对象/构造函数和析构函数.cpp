#include <iostream>
using namespace std;

/*
如果只提供了有参构造函数
则编译器不会提供默认的构造函数，如果要用到new 类数组操作则需要提供默认构造函数
*/

class Person
{
private:
    /* data */
public:
    Person(/* args */);  //���캯��  def __init__()
    Person(int,int);
    ~Person();  //��������  �ڶ����ͷź���Զ�����
};

Person::Person(/* args */)
{
    cout << 111 << endl;
}

Person::Person(int,int)
{
    cout << 123 << endl;
}

//���캯�����Է�������

Person::~Person()
{
    cout << 123124 << endl;
}
//�����������ܴ��������Ҳ��������

void test()
{
    Person p;
    Person a2(1,1);
}

int main()
{
    test();

    system("pause");

    return 0;
}