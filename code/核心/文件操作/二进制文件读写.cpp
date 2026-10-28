#include <iostream>
#include <fstream>
using namespace std;

/*
在二进制文件的写入和读取中，一般不会写入string形式的数据
因为string数据含有指针和长度等复杂内容，写入二进制容易出错

传入的内存地址为内存缓冲区的地址开头
二进制文件在写入的过程中需要在传入char指针类型的地址来作为数据内存地址为的开始，再传入数据的内存大小从而把数据解读出来写入二进制文件中
(const char*)&p 当中p为要写入的数据

二进制文件在读取的时候同理，传入内存地址的类型为char* 不加const的原因是因为要对这个内存进行修改
写入的数据和读取的数据要用同一个类型的变量来接收
*/

class person
{
private:
    /* data */
public:
    person(/* args */);
    ~person();

    int age;
    char name[64] = "zhangsan"; //姓名，因为是二进制文件的读写操作，用string会容易出问题
};

person::person(/* args */)
{
}

person::~person()
{
}


void test()
{
    person p;
    p.age = 18;

    ofstream ofs("person.bin",ios::out | ios::binary);
    //写入文件，提供地址(const char*)类型指示数据在内存缓冲区的开头位置

    ofs.write((const char*)&p , sizeof(person));

    ofs.close();
}

void test1()
{
    person p;

    ifstream ifs("person.bin",ios::in | ios::binary);

    //读取文件
    ifs.read((char*)&p , sizeof(person));

    cout << p.name << endl;
    cout << p.age << endl;

    ifs.close();

}

int main()
{
    test();
    test1();

    return 0;
}