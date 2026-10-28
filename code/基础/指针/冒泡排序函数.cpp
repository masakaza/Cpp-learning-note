#include <iostream>
using namespace std;

void bubbleSort(int* arr , int len)
{
    for (int i = 0; i < len-1; i++)
    {
        for (int j = 0; j < len-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                    
            }
                
        }
            
    }
        
}

int main()
{
    int arr[] = {4,3,6,9,1,2,10,8,7,5};

    bubbleSort(arr,size(arr));
    for (int i = 0; i < size(arr); i++)
    {
        cout << arr[i] << " ";
    }
    
    cout << endl;



    system("pause");

    return 0;
}