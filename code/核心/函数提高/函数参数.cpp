#include <iostream>
using namespace std;

/*
默认参数往后必须都是默认参数
*/

void show(int a ,int b = 10,int c = 100) //这里面的b和c都是默认参数
{   
    b = a; 
    return;
}

// void show(int a,int b = 20); //如果函数里面有默认参数，声明函数的时候不能有默认参数
//函数定义或者函数声明 两个语句里面只能有一个有默认参数
void show(int a = 10 , int b,int c);

int main()
{
    
    show(10);

    system("pause");

    return 0;
}