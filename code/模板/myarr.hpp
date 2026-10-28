#pragma once
#include <iostream>
using namespace std;

/*
重载操作之所以返回引用，其目的之一是能让他们进行连锁的操作，比如连等或者 arr[0] = 100
其中的arr[0]返回数组内部对象的引用来进行赋等操作
*/

template <typename T>
class myarr
{
private:
    T* arr = nullptr;
    int arr_num = 0; // 数组容量
    int size = 0;    // 数组元素数量
public:
    myarr(int);
    myarr(const myarr &);
    ~myarr();
    myarr<T>& operator=(const myarr<T>&);
    void add(const T &); // 尾插法 因为传入的不一定是数值，还可以是类对象，所以要用const引用防止修改
    void del();          // 尾删法
    T &operator[](int);
    int get_size() { return size; };
    int get_arrnum() { return arr_num; };
};

template <typename T>
myarr<T>::myarr(int num)
{
    arr_num = num;
    //如果T为一个类对象，那么要提供默认构造参数，不然内存堆区内存创建会失败
    arr = new T[arr_num];
}

template <typename T>
myarr<T>::myarr(const myarr &m)
{
    arr_num = m.arr_num;
    size = m.size;

    arr = new T[arr_num];
    if (m.size != 0)
    {
        for (int i = 0; i < m.size; i++)
        {
            arr[i] = m.arr[i];
        }
    }
}

template <typename T>
myarr<T>::~myarr()
{
    delete[] arr;
}

// 等号赋值操作
// 在赋等操作中，要把数组对象内部的数据都赋等，如果数组的容量不变，则会出现越界操作，所以要先释放原来的数组重新new一个
template <typename T>
myarr<T>& myarr<T>::operator=(const myarr<T>& m)
{
    // 清空原来数据
    if (arr)
    {
        delete[] arr;
        arr = nullptr;
    }

    arr_num = m.arr_num;
    size = m.size;
    arr = new T[arr_num];

    for (int i = 0; i < m.size; i++)
    {
        arr[i] = m.arr[i];
    }

    return *this;
}

template <typename T>
void myarr<T>::add(const T &n)
{
    if (size == arr_num)
    {
        cout << "数组已满" << endl;
        return;
    }

    arr[size] = n;
    size++;
}

template <typename T>
void myarr<T>::del()
{
    if (size == 0)
    {
        cout << "数组已空" << endl;
        return;
    }

    size--;
}

// 此处返回引用是希望能进行 arr[0] = 100的连锁操作
template <typename T>
T& myarr<T>::operator[](int index)
{
    return arr[index];
}
