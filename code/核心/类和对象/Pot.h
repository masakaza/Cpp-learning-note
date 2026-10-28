#pragma once //防止头文件被重复包含
// #include <iostream>
// using namespace std;

class Pot
{
private:
    int p_x;
    int p_y;

public:
    Pot();
    int get_x();
    int get_y();
};