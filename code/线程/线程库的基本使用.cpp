#include <iostream>
#include <thread>
using namespace std;

/*
main函数中的程序可以理解为主线程
通过thread 来创建子线程对象，并且传入函数来让他执行
如果要传递一个引用对象，要用 std::ref
*/

void out_str(string n)
{
    cout << n << endl;
}

int main()
{
    thread t(out_str,"hello");
    t.join(); //通过join来等待子线程结束再往下运行

    return 0;
}
