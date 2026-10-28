#include <iostream>
using namespace std;

/*
案例使用选择排序算法，能把最大的数值放在左边
利用函数模板排序int和char类型的数组
*/

template<typename T>
void tswap(T& a , T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
void sort(T arr[] , int size)
{
    for (int i = 0; i < size; i++)
    {
        int max = i;
        for (int j = i+1 ; j < size; j++)
        {
            if (arr[max] < arr[j])
            {
                max = j;
            }
            
        }
        
        if (max != i)
        {
            tswap(arr[max] , arr[i]);
        }
        
    }
    
}

template<typename T>
void printarr(T arr[],int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
    }
    
    cout << endl;
}


int main()
{
    char c_arr[] = "bahdfjlw";
    sort(c_arr,size(c_arr));
    printarr(c_arr,size(c_arr));

    int i_arr[] = {1,4,2,6,9,4,7,2,0};
    sort(i_arr,size(i_arr));
    printarr(i_arr,size(i_arr));

    return 0;
}