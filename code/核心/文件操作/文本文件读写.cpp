#include <iostream>
using namespace std;
#include <fstream>

/*
如果没有相关文件则会创建文本
写文件： ofstream   out_file_stream 输出文件流，所以是文件写入
读文件： ifstream   in_file_stream 输入文件流，所以是文件读取
读写文件: fstream   file_stream 文件工作流，所以是文件读写
*/
/*
ios::in  以只读打开文件
ios::out 以只写来打开文件，在不指定文件模式的情况下默认是这个模式，会清空全部的内容重新写入
ios::ate 把文件写入的指针放在文件的末尾  (一般用不上，一般会用app)
ios::app 以追加的方式写文件
ios::trunc 打开文件时会清空原有内容
ios::binary 二进制方式读写文件
*/

void test()
{
    ofstream ofs;
    ofs.open("test.txt",ios::out);

    if (!ofs.is_open())
    {
        cout << "文件打开错误" << endl;
        return;
    }
    
    ofs << "名字： 张三" << endl;
    ofs << "性别： 男" << endl;
    ofs << "年龄： 18" << endl;

    ofs.close();
}

void test1()
{
    ifstream ifs;
    ifs.open("test.txt",ios::in);

    //方法一
    char buf[1024] = {0};   //相当于固定长度的字符串
    while (ifs >> buf)   //读取固定长度，遇到换行符就停止
    {
        cout << buf << endl;
    }
    
    //方法二
    while (ifs.getline(buf,sizeof(buf)))   //读取一整行，如果长度超出字符数量或者遇到换行符就停止
    {
        cout << buf << endl;
    }

    string bufs;

    while (getline(ifs,bufs))  //用字符串的方式接收数据读取一整行,只会在遇到换行符或者EOF的时候才会终止
    {
        cout << bufs << endl;
    }
    
    //方法四
    char ch;
    while (ifs.get(ch)) //读取单个字符
    {
        cout << ch << endl;
    }
    
    ifs.close();
    
}

int main()
{
    test();
    test1();


    return 0;
}